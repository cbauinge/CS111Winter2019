#include "Solver.h"
#include "lapacke.h"
#include "Writer.h"
#include <iostream>
#include <algorithm>
#include <ostream>

//#define DEBUG


Solver::Solver()
{
}


int Solver::Solve(const Domain * const domain) 
{
    std::cout << "Starting solving process..." << std::endl;
    lapack_int info, lda, ldb , nrhs;
    
    //the number of the inner nodes determines the size of our coefficient matrix
    unsigned n = domain->GetMesh()->GetInnerNodeIds().size(); 
    std::cout << "\t degrees of freedom in the matrix = " << n << std::endl;
    nrhs = 1; //we only have 1 rhs
    lda = n; //the dimension of a is n
    ldb = n; //leading dimension of b.
    
    double* A = new double[n*n];
    double* b = new double[n*nrhs];
    int ipiv[n];
    
    std::cout << "\tStart Generating SoE..." << std::endl;
    GenerateSoE(domain, A, b, n);
    std::cout << "\t...Finished Generating SoE" << std::endl;
    
    std::cout << "\tStart solving the SoE..." << std::endl;
    info = LAPACKE_dgesv(LAPACK_COL_MAJOR, n, nrhs, A, lda, ipiv, b, ldb);
    if (info != 0)
    {
        std::cout << "Something went wrong solving the system. Info = " << info << std::endl;
        return info;
    }
    std::cout << "\t...Finished Solving SoE" << std::endl;
    
    Writer writer;
    writer.WriteSolution(domain->GetMesh(), b, n, "result", "results", Writer::EFormat::CSV);
    std::cout << "Finished Writing Solution to file" << std::endl;
    
    delete [] A;
    delete [] b;
    
    return info;
}



std::vector<int> Solver::GeneratePositionInMatrixLookup(const std::vector<int>& Ids) const
{
    auto maxIter = std::max_element(Ids.begin(), Ids.end());
#ifdef DEBUG
    std::cout << "maximum inner id = " << *maxIter << "\tsize ids = " << Ids.size() << std::endl;
#endif
    std::vector<int> positions(*maxIter +1);
    
    for (unsigned i = 0; i < Ids.size(); i++)
    {   
#ifdef DEBUG
        std::cout << "id = " << Ids[i] << " at position " << i << std::endl;
#endif
        positions[Ids[i]] = i;
    }
    
    return positions;
}


void Solver::GenerateSoE(const Domain* const domain, double * A, double * b, unsigned n)
{
    #ifdef DEBUG
    std::cout <<"start GenerateSoE" << std::endl;
    std::cout << "n = " << n << std::endl;
    #endif
    
    const std::vector<int>& inner_node_ids = domain->GetMesh()->GetInnerNodeIds();
    std::vector<int> positions = 
        GeneratePositionInMatrixLookup(inner_node_ids);
    
    for (unsigned i = 0; i < n; i++)
    {
        int nodei = inner_node_ids[i]; 
#ifdef DEBUG
        std::cout << "Setting up for node " << nodei << "..." << std::endl;
#endif
        
        //The energyfucntion mithgt depend on the simplex at some point which is why I put it here.
        const EnergyFunction* energyfct = domain->GetEnergyFunction();
        
        //The shape function might depend on the simplex at some point which is why i put it here
        const ShapeFunction* shapefct = domain->GetShapeFunction();
        
        //SETUP THE NON DIAGONAL ENTRIES
        
        //get the edges to the inner neighbours.
        const std::vector<int>& edges2innernodes = 
            domain->GetMesh()->GetEdgesToInnerNodesFromNode(nodei);

        
        //iterate through all the neighbouring inner nodes.
        for (unsigned l = 0; l < edges2innernodes.size(); l++)
        {            
            //Edge to the other node
            int edgeid = edges2innernodes[l];
#ifdef DEBUG
            std::cout << "Edge " << edgeid << std::endl;
#endif
            const Edge* e = domain->GetMesh()->GetEdge(edgeid);
            
            //id of the other node
            int nodej = ( *domain->GetMesh()->GetNode(nodei) != *e->GetNode(0) ) ? 
                domain->GetMesh()->GetNodeId(e->GetNode(0)) : domain->GetMesh()->GetNodeId(e->GetNode(1));
#ifdef DEBUG
            std::cout << "\tNode j = " << nodej << std::endl;
#endif
            
            //position in the matrix
            int j = positions[nodej];
            
            //Get the elements ids over which we need to integrate
            const std::vector<int>& elements = domain->GetMesh()->GetElementsFromEdge(edgeid);
            
            double integral = 0.0;
            
            for (unsigned iter_simplices = 0; iter_simplices < elements.size(); iter_simplices++)
            {
#ifdef DEBUG
                std::cout << "\t\tElement " << elements[iter_simplices] << std::endl;
#endif
                const Element* s = domain->GetMesh()->GetElement(elements[iter_simplices]);
                
                int localnodei = s->GetLocalNodeId(domain->GetMesh()->GetNode(nodei));
                int localnodej = s->GetLocalNodeId(domain->GetMesh()->GetNode(nodej));
#ifdef DEBUG
                std::cout << "\t\t\tlocal node ids = " << localnodei << ", " << localnodej << std::endl;
#endif
                
                if (localnodei == -1 || localnodej == -1)
                    throw std::invalid_argument("Node is not part of the simplex in Solver::GenerateSoE");
                
                integral += domain->GetIntegrator()->Integrate(s, energyfct, shapefct, localnodei, localnodej);
#ifdef DEBUG
                std::cout << "\t\tIntegral = " << integral << std::endl;
#endif
                
            }   
            if (nodei != nodej) {//ATTENTION this if is just for the quick and dirty version since we do not shift the elements to the unit element.
                if (domain->GetMesh()->GetNode(nodei)->GetX() != domain->GetMesh()->GetNode(nodej)->GetX() &&
                    domain->GetMesh()->GetNode(nodei)->GetY() != domain->GetMesh()->GetNode(nodej)->GetY())
                    integral = 0;
                else
                    integral = -1.0;
                
            }
            
            
            #ifdef DEBUG
            std::cout << "A[" << i << "," << j << "] = " << integral << std::endl;
            #endif
            
            A[i + j*n] = integral;
        }
        
        
        //SETUP THE DIAGONAL ENTRIES
            
        //the integral of the shape function attached to the point with itself requires all neighbouring simplizes
        const std::vector<int>& elements = domain->GetMesh()->GetElementsFromNode(nodei);
        
        double vdiag = 0.0;
        for (unsigned iter_simplices = 0; iter_simplices < elements.size(); iter_simplices++)
        {
#ifdef DEBUG
            std::cout << "Element " << iter_simplices << std::endl;
#endif
            const Element* s = domain->GetMesh()->GetElement(elements[iter_simplices]);
            int localnodei = s->GetLocalNodeId(domain->GetMesh()->GetNode(nodei));
            
            
            vdiag += domain->GetIntegrator()->Integrate(s, energyfct, shapefct, localnodei, localnodei);
        }
        
        #ifdef DEBUG
        std::cout << "A[" << i << "," << i << "] = " << vdiag << std::endl;
        #endif
        A[i*n+i] = vdiag;
         
        
        b[i] = 1;
    }    
#ifdef DEBUG
    DumpSoE(A, b, n);
#endif
}



void Solver::DumpSoE(double *A, double* b, int n) const
{
    std::ofstream ofs("Matrix.data", std::ofstream::out);
    if (!ofs.is_open())
    {
        std::cout << "Couldnt write matrix" << std::endl;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ofs << A[i + j*n];
            if (j < n-1)
                ofs << ", ";        
        }
        ofs << std::endl;
    }
    
    ofs.close();
    
    std::ofstream ofrhs("RHS.data", std::ofstream::out);
    if (!ofrhs.is_open())
    {
        std::cout << "Couldnt write matrix" << std::endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        ofrhs << b[i];
        ofrhs << std::endl;
    }
    
    ofrhs.close();
}








