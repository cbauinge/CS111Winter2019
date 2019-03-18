#ifndef LAPACKSOLVER_H
#define LAPACKSOLVER_H

#include "Solver.h"



/*! \brief Solver class using Lapacke linrary to solve the SoE.
 *
 *  Derived class from Solver.
 */
class LapackSolver : public Solver
{
public:
    LapackSolver();
    virtual ~LapackSolver() {}
    virtual int Solve(const Domain * const domain);

private:
    double* FormatMatrix(const Matrix<double>& A) const;
    double* FormatRHS(const Vector<double>& b) const;

};



#endif /* LAPACKSOLVER_H */