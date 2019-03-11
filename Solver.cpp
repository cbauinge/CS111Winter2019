#include "Solver.h"
#include "lapacke.h"
#include "Writer.h"
#include "Matrix.h"
#include <iostream>
#include <algorithm>
#include <ostream>
#include <exception>

//#define DEBUG


Solver::Solver()
{
}

std::vector<int> Solver::GeneratePositionInMatrixLookup(const std::vector<int>& Ids, int n) const
{
    std::vector<int> positions(n, -1);
    
    for (unsigned i = 0; i < Ids.size(); i++)
    {   
        positions[Ids[i]] = i;
    }
    
    return positions;
}


void Solver::GenerateSoE(const Domain* const domain, Matrix<double>& A, Vector<double>& b)
{
    std::vector<const Element* > elems = domain->GetMesh()->GetpElements();
    std::vector<int> positions = GeneratePositionInMatrixLookup(domain->GetMesh()->GetInnerNodeIds(), domain->GetMesh()->GetNumberNodes());

    #pragma omp parallel for
    for (int eiter = 0; eiter < elems.size(); eiter++)
    {
        const Element* e = elems[eiter];
        //get the evaluations of all the nergy functions on the current element 
        Matrix<double> energy = domain->GetIntegrator()->Integrate(e, domain->GetEquation()->GetEnergyFunction(), domain->GetShapeFunction());
        //now we add these to the corresponding matrix.
        const std::vector<Node*>& local_nodes = e->GetNodes();
        std::vector<int> matrixpos(local_nodes.size());
        for (int i = 0; i < local_nodes.size(); i++) 
        {
            matrixpos[i] = positions[domain->GetMesh()->GetNodeId(local_nodes[i])];
        }

        for (int i = 0; i < energy.GetDimensionRows(); i++)
        {
            if (matrixpos[i] != -1)
            {
                for (int j = 0; j < energy.GetDimensionCols(); j++) //go over all the neighboring nodes
                {
                    if (matrixpos[j] != -1)
                        A[matrixpos[i]][matrixpos[j]] += energy[i][j];
                    else //this means a neighboreing node is a boundary node and need to be added to the right handside 
                    {
                        if (domain->GetBoundaryCondition()->GetType() == BoundaryCondition::Type::Dirichlet)
                            b[matrixpos[i]] -= energy[i][j]*domain->GetBoundaryCondition()->Eval(*local_nodes[j]);
                        else
                            throw std::invalid_argument("Other BCs than Dirichlet not yet supported. Solver::GenerateSoE");
                            
                    }
                }
                b[matrixpos[i]] += 1.0/3.0*e->GetArea()*domain->GetEquation()->GetSourceFunction()->Eval(*local_nodes[i]); //this needs to be generalized for different shape functions
            }
                
        }
    }

    #ifdef DEBUG
    DumpSoE(A, b);
    #endif
}



void Solver::DumpSoE(const Matrix<double>& A, const Vector<double>& b) const
{
    std::ofstream ofs("Matrix.data", std::ofstream::out);
    if (!ofs.is_open())
    {
        std::cout << "Couldnt write matrix" << std::endl;
        return;
    }
    
    ofs << A << std::endl;
    
    ofs.close();
    
    std::ofstream ofrhs("RHS.data", std::ofstream::out);
    if (!ofrhs.is_open())
    {
        std::cout << "Couldnt write matrix" << std::endl;
        return;
    }
    ofrhs << b << std::endl;
    
    ofrhs.close();
}








