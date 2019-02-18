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
    
    //the number of the inner nodes determines the size of our coefficient matrix
    n = domain->GetMesh()->GetInnerNodeIds.size(); 
    nrhs = 1; //we only have 1 rhs
    lda = n; //the dimension of a is n
    ldb = n; //the dimension of b is n
    
    double A[n*n] = {1};
    double b[n*nrhs] = {1};
    int ipiv[n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //setup A by calling the integrator for each inner node and the integrals over the respective elements.
        }
        
        //setup b. Depends on the rhs in the system.
    }
    
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
