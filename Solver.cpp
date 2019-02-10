#include "Solver.h"
#include "lapacke.h"
#include "Writer.h"
#include <iostream>

extern 


Solver::Solver()
{
}


int Solver::Solve(const Domain * const domain) 
{
    
    lapack_int info, n, lda, ldb , nrhs;
    
    n = 1;
    nrhs = 1;
    lda = n;
    ldb = n;
    
    double A[n*n] = {1};
    double b[n*nrhs] = {1};
    int ipiv[n];
    
    info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, A, lda, ipiv, b, ldb);
    if (info != 0)
    {
        std::cout << "Something went wrong solving the system. Info = " << info << std::endl;
        return info;
    }
    
    Writer writer;
    writer.WriteSolution(domain->GetMesh(), b, n, "result", Writer::EFormat::CSV);
    
    
    return info;
}
