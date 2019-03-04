#include "Solver.h"
#include "lapacke.h"
#include "Writer.h"
#include "Matrix.h"
#include <iostream>
#include <algorithm>
#include <ostream>

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


void Solver::GenerateSoE(const Domain* const domain, Matrix<double>& A, Vector<double>& b, unsigned n)
{
    std::vector<const Element* > elems = domain->GetMesh()->GetpElements();
    std::vector<int> positions = GeneratePositionInMatrixLookup(domain->GetMesh()->GetInnerNodeIds(), domain->GetMesh()->GetNumberNodes());

    for (auto e : elems)
    {
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
                for (int j = 0; j < energy.GetDimensionCols(); j++)
                {
                    if (matrixpos[j] != -1)
                        A[matrixpos[i]][matrixpos[j]] += energy[i][j];
                }
                b[matrixpos[i]] += 1.0/3.0*e->GetArea()*domain->GetEquation()->GetSourceFunction()->Eval(*local_nodes[i]);
            }    
        }
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








