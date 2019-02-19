#include "Solver.h"
#include "lapacke.h"
#include "Writer.h"
#include <iostream>

//#define DEBUG


Solver::Solver()
{
}


int Solver::Solve(const Domain * const domain) 
{
    
    lapack_int info, lda, ldb , nrhs;
    
    //the number of the inner nodes determines the size of our coefficient matrix
    unsigned n = domain->GetMesh()->GetInnerNodeIds().size(); 
    nrhs = 1; //we only have 1 rhs
    lda = n; //the dimension of a is n
    ldb = 1; //the dimension of b is n
    
    double A[n*n];
    double b[n*nrhs];
    int ipiv[n];
    
    GenerateSoE(domain, A, b, n);
    
    info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, A, lda, ipiv, b, ldb);
    if (info != 0)
    {
        std::cout << "Something went wrong solving the system. Info = " << info << std::endl;
        return info;
    }
    
    Writer writer;
    writer.WriteSolution(domain->GetMesh(), b, n, "result", "results", Writer::EFormat::CSV);
    
    
    return info;
}



std::vector<int> Solver::GeneratePositionInMatrixLookup(const std::vector<int>& Ids) const
{
    std::vector<int> positions(1);
    
    for (unsigned i = 0; i < Ids.size(); i++)
    {
        if (positions.size() <= Ids[i])
            positions.resize(Ids[i]);
        
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
            const Edge* e = domain->GetMesh()->GetEdge(edgeid);
            
            //id of the other node
            int nodej = ( nodei != e->GetNode(0) ) ? e->GetNode(0) : e->GetNode(1); 
            
            //position in the matrix
            int j = positions[nodej];
            
            //Get the simplices ids over which we need to integrate
            const std::vector<int>& simplices = domain->GetMesh()->GetSimplicesFromEdge(edgeid);
            
            double integral = 0.0;
            
            for (unsigned iter_simplices = 0; iter_simplices < simplices.size(); iter_simplices++)
            {
                const Simplex* s = domain->GetMesh()->GetSimplex(simplices[iter_simplices]);
                
                
                integral += domain->GetIntegrator()->Integrate(s, energyfct, shapefct, nodei, nodej);
            }            
            
            #ifdef DEBUG
            std::cout << "A[" << i << "," << j << "] = " << integral << std::endl;
            #endif
            
            A[i*n + j] = integral;
        }
        
        
        //SETUP THE DIAGONAL ENTRIES
            
        //the integral of the shape function attached to the point with itself requires all neighbouring simplizes
        const std::vector<int>& simplices = domain->GetMesh()->GetSimplicesFromNode(nodei);
        
        double vdiag = 0.0;
        for (unsigned iter_simplices = 0; iter_simplices < simplices.size(); iter_simplices++)
        {
#ifdef DEBUG
            std::cout << "Simplex " << iter_simplices << std::endl;
#endif
            const Simplex* s = domain->GetMesh()->GetSimplex(simplices[iter_simplices]);
            
            
            vdiag += domain->GetIntegrator()->Integrate(s, energyfct, shapefct, nodei, nodei);
        }
        
        #ifdef DEBUG
        std::cout << "A[" << i << "," << i << "] = " << vdiag << std::endl;
        #endif
        A[i*n+i] = vdiag;
         
        //setup b. Depends on the rhs in the system.
        //for now, we assume b = 0;
        //b[0] = 1; //for tests!
    }    
}












