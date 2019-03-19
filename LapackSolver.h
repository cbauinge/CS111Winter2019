#ifndef LAPACKSOLVER_H
#define LAPACKSOLVER_H

#include "Solver.h"



/*! \brief Solver class using Lapacke library to solve the SoE.
 *
 *  Derived class from Solver. Calls Lapack to solve linear system of equations
 */
class LapackSolver : public Solver
{
public:
    /*! \brief Constructor. Doing nothing.
    */
    LapackSolver();
    /*! \brief Destructor. Doing nothing.
    */
    virtual ~LapackSolver() {}
    /*! \brief Solve method.
    *
    * Generates the SoE using the base class member function, copies the SoE to the correct format for Lapack, calls Lapack library on
    * it and writes solution to harddrive.
    */
    virtual int Solve(const Domain * const domain);

private:
    /*! \brief Formats the matrix from my own format to the lapack specific format.
    */
    double* FormatMatrix(const Matrix<double>& A) const;
    /*! \brief Formats the vector from my own format to the lapack specific format.
    */
    double* FormatRHS(const Vector<double>& b) const;

};



#endif /* LAPACKSOLVER_H */