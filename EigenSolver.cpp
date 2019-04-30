#include "EigenSolver.h"

#include <iostream>

#include "Writer.h"


EigenSolver::EigenSolver()
{

}

EigenSolver::~EigenSolver() {}

int EigenSolver::Solve(const Domain * const domain)
{
    std::cout << "Starting solving process using Eigen..." << std::endl;
    
    //the number of the inner nodes determines the size of our coefficient matrix
    unsigned n = domain->GetMesh()->GetInnerNodeIds().size(); 
    std::cout << "\t degrees of freedom in the matrix = " << n << std::endl;
    
    Matrix<double> A(n, n);
    Vector<double> b(n);
    
    std::cout << "\tStart Generating SoE..." << std::endl;
    GenerateSoE(domain, A, b);
    std::cout << "\t...Finished Generating SoE" << std::endl;
    
    std::cout << "\tStart solving the SoE..." << std::endl;
    Eigen::SparseMatrix<double> As = FormatMatrix(A);
    Eigen::VectorXd bs = FormatRHS(b);
    
    Eigen::SimplicialCholesky<Eigen::SparseMatrix<double> > chol(As);
    Eigen::VectorXd result = chol.solve(bs);

    std::cout << "\t...Finished Solving SoE" << std::endl;
    
    Writer writer;
    writer.WriteSolution<Eigen::VectorXd>(domain->GetMesh(), result, n, "result", "results", Writer::EFormat::CSV);
    std::cout << "Finished Writing Solution to file" << std::endl;
    
    return 0;
}


Eigen::SparseMatrix<double> EigenSolver::FormatMatrix(const Matrix<double>& A) const
{
    std::vector<Eigen::Triplet<double> > tripletList;
    tripletList.reserve(5*A.GetDimensionCols());

    //#pragma omp parallel for
    for (int i = 0; i < A.GetDimensionRows(); i++)
    {
        for (int j = 0; j < A.GetDimensionCols(); j++)
        {
            if (A.Exists(i, j))
            {
                if (A[i][j] != 0.0)
                {
                    tripletList.push_back(Eigen::Triplet<double>(i, j, A[i][j]));
                }
            }
        }
    }

    Eigen::SparseMatrix<double> M(A.GetDimensionRows(), A.GetDimensionCols());
    M.setFromTriplets(tripletList.begin(), tripletList.end());

    return M;
}


Eigen::VectorXd EigenSolver::FormatRHS(const Vector<double>& b) const
{
    Eigen::VectorXd v(b.GetDimension());

    //#pragma omp parallel for
    for (int i = 0; i < b.GetDimension(); i++)
    {
        if (b.Exists(i))
            v[i] = b[i];
        else
        {
            v[i] = 0.0;
        }        
    }
    return v;
}
