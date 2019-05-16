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
    /*! \brief Constructor. Doing nothing.
    */
    EigenSolver();
    /*! \brief Destructor. Doing nothing.
    */
    virtual ~EigenSolver();
    /*! \brief Solve method.
    *
    * Generates the SoE using the base class member function, copies the SoE to the correct format for Eigen, calls Eigen library on
    * it and writes solution to harddrive.
    */
    virtual int Solve(const Domain * const domain);

private:
    /*! \brief Formats the matrix from my own format to the eigen specific format.
    */
    Eigen::SparseMatrix<double> FormatMatrix(const Matrix<double>& A) const;
    /*! \brief Formats the vector from my own format to the eigen specific format.
    */
    Eigen::VectorXd FormatRHS(const Vector<double>& b) const;
};




#endif /* EIGENSOLVER_H */
