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
    friend class PolynomialTest;
    
public:
    Polynomial() : Polynomial(0, 0) {}

    /*! \brief constructor. Sets up a dim - dimensional polynomial of degree deg.
    *
    * Currently works onyl for dim = 2 and deg = 1.
    */
    Polynomial(int dim, int deg) : dimension(dim), degree(deg) {}
    
    ~Polynomial() {}
    
    /*! \brief Getter for the dimension (= number of variables)
    */
    int GetDimension() const {return dimension;}
        
        
    std::map<Multiindex, double>& GetCoefficients() {return coeffs;}
    const std::map<Multiindex, double>& GetCoefficients() const {return coeffs;}
    
    /*! \brief Get the derivative polynomial with respect to variable 'variable'
    *
    * /param[in] variable The variable with which we derive the polynomial.
    */
    Polynomial Derivative(int variable) const;
    
    /*! \brief Evaluate the polynomial at the point x.
    *
    * \param[in] x Point where we wwant to evalute the polynomial. Attenion: the size of x needs to equal dimension.
    */
    double operator() (const Node& x) const;
    

    
private: 
    int dimension; //indicates the number of (possible) variables
    int degree; //indicates the highest monomial order
    std::map<Multiindex, double> coeffs;
    
};

std::ostream& operator<<(std::ostream& ofs, const Polynomial& poly);


#endif /* POLYNOMIAL_H */
