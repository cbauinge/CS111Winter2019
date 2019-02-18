#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Multiindex.h"
#include "Node.h"
#include <map>


class Polynomial
{   
    
public:
    Polynomial() : Polynomial(0, 0) {}
    Polynomial(int dim, int deg) : dimension(dim), degree(deg) {}
    
    ~Polynomial() {}
        
        
    std::map<Multiindex, double>& GetCoefficients() {return coeffs;}
    
    Polynomial Derivative(int variable) const;
    
    double operator() (const Node& x) const;
    

    
private: 
    int dimension;
    int degree;
    std::map<Multiindex, double> coeffs;
    
};


#endif /* POLYNOMIAL_H */
