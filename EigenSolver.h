#ifndef EIGENSOLVER_H
#define EIGENSOLVER_H


#include "Solver.h"

#include <Eigen/Sparse>
#include <Eigen/Core>


/*! \brief Class representing the solver using Eigen library.
 *
 *  Derived from abstract solver class. Depends on Eigen.
 */
class EigenSolver : public Solver
{
public:
    EigenSolver();
    virtual ~EigenSolver();
    virtual int Solve(const Domain * const domain);

private:
    Eigen::SparseMatrix<double> FormatMatrix(const Matrix<double>& A) const;
    Eigen::VectorXd FormatRHS(const Vector<double>& b) const;
};




#endif /* EIGENSOLVER_H */