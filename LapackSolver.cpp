#include "LapackSolver.h"
#include <iostream>
#include "lapacke.h"
#include "Solver.h"
#include "Writer.h"


LapackSolver::LapackSolver()
{

}

int LapackSolver::Solve(const Domain * const domain) 
{
    std::cout << "Starting solving process using Lapack..." << std::endl;
    lapack_int info, lda, ldb , nrhs;
    
    //the number of the inner nodes determines the size of our coefficient matrix
    unsigned n = domain->GetMesh()->GetInnerNodeIds().size(); 
    std::cout << "\t degrees of freedom in the matrix = " << n << std::endl;
    nrhs = 1; //we only have 1 rhs
    lda = n; //the dimension of a is n
    ldb = n; //leading dimension of b.
    
    Matrix<double> A(n, n);
    Vector<double> b(n);
    int ipiv[n];
    
    std::cout << "\tStart Generating SoE..." << std::endl;
    GenerateSoE(domain, A, b);
    std::cout << "\t...Finished Generating SoE" << std::endl;
    
    std::cout << "\tStart solving the SoE..." << std::endl;
    double* As = FormatMatrix(A);
    double* bs = FormatRHS(b);
    info = LAPACKE_dgesv(LAPACK_COL_MAJOR, n, nrhs, As, lda, ipiv, bs, ldb);
    if (info != 0)
    {
        std::cout << "Something went wrong solving the system. Info = " << info << std::endl;
        return info;
    }
    std::cout << "\t...Finished Solving SoE" << std::endl;
    
    Writer writer;
    writer.WriteSolution(domain->GetMesh(), bs, n, "result", "results", Writer::EFormat::CSV);
    std::cout << "Finished Writing Solution to file" << std::endl;
    
    delete [] As;
    delete [] bs;
    
    return info;
}


double* LapackSolver::FormatMatrix(const Matrix<double>& A) const
{
    double* As = new double[A.GetDimensionRows()*A.GetDimensionCols()];

    for (int i = 0; i < A.GetDimensionRows(); i++)
    {
        for (int j = 0; j < A.GetDimensionCols(); j++)
        {
            if (A.Exists(i, j))
                As[i + A.GetDimensionRows()*j] = A[i][j];
            else
                As[i + A.GetDimensionRows()*j] = 0.0;
        }
    }

    return As;
}

double* LapackSolver::FormatRHS(const Vector<double>& b) const
{
    double* bs = new double[b.GetDimension()]; 

    for (int i = 0; i < b.GetDimension(); i++)
    {
        bs[i] = b[i];    
    }

    return bs;
}


