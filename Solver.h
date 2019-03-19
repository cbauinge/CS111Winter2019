#ifndef SOLVER_H
#define SOLVER_H


#include "Domain.h"
#include "Matrix.h"
#include "Vector.h"
#include <stdlib.h>


/*! \brief Abstract Solver class.
 *
 *  Gives access to simple output functionaility, generating the SoE and an abstract 'Solve' function.
 */
class Solver
{
public:
    Solver();
    virtual ~Solver() {}
    virtual int Solve(const Domain * const domain) = 0;

protected:
    /*! \brief function that takes a vector of ids and generates a vector,
    * where the position in the vector is the id and the value 
    * is the position in the original vector
    * */
    std::vector<int> GeneratePositionInMatrixLookup(const std::vector<int>& Ids, int n) const;
    
    /*! \brief Generate A, b.
    */
    void GenerateSoE(const Domain* const domain, Matrix<double>& A, Vector<double>& b);


    void DumpSoE(const Matrix<double>& A, const Vector<double>& b) const;

};

#endif /* SOLVER_H */
