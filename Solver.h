#ifndef SOLVER_H
#define SOLVER_H


#include "Domain.h"

class Solver
{
public:
    Solver();
    int Solve(const Domain * const domain);

private:
    //function that takes a vector of ids and generates a vector,
    //where the position in the vector is the id and the value 
    //is the position in the original vector
    std::vector<int> GeneratePositionInMatrixLookup(const std::vector<int>& Ids) const;
    
    //Generate A, b
    void GenerateSoE(const Domain* const domain, double * A, double * b, unsigned n);
    void DumpSoE(double *A, double* b, int n) const;

};

#endif /* SOLVER_H */
