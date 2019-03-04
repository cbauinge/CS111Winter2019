#ifndef SOLVER_H
#define SOLVER_H


#include "Domain.h"
#include "Matrix.h"
#include "Vector.h"

class Solver
{
public:
    Solver();
    virtual ~Solver() {}
    virtual int Solve(const Domain * const domain) = 0;

protected:
    //function that takes a vector of ids and generates a vector,
    //where the position in the vector is the id and the value 
    //is the position in the original vector
    std::vector<int> GeneratePositionInMatrixLookup(const std::vector<int>& Ids, int n) const;
    
    //Generate A, b
    void GenerateSoE(const Domain* const domain, Matrix<double>& A, Vector<double>& b, unsigned n);


    void DumpSoE(double *A, double* b, int n) const;

};

#endif /* SOLVER_H */
