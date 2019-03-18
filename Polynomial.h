#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Multiindex.h"
#include "Node.h"
#include <map>
#include <ostream>

/*! \brief Class representing a multidemsnional polynomial.
 *
 */
class Polynomial
{   
    
public:
    Polynomial() : Polynomial(0, 0) {}
    Polynomial(int dim, int deg) : dimension(dim), degree(deg) {}
    
    ~Polynomial() {}
    
    int GetDimension() const {return dimension;}
        
        
    std::map<Multiindex, double>& GetCoefficients() {return coeffs;}
    const std::map<Multiindex, double>& GetCoefficients() const {return coeffs;}
    
    Polynomial Derivative(int variable) const;
    
    double operator() (const Node& x) const;
    

    
private: 
    int dimension; //indicates the number of (possible) variables
    int degree; //indicates the highest monomial order
    std::map<Multiindex, double> coeffs;
    
};

std::ostream& operator<<(std::ostream& ofs, const Polynomial& poly);


#endif /* POLYNOMIAL_H */
