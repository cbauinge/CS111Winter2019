#ifndef POLYNOMIALSHAPEFUNCTION_H
#define POLYNOMIALSHAPEFUNCTION_H

#include "ShapeFunction.h"
#include "Node.h"
#include "Polynomial.h"
#include "Vector.h"
#include "Element.h"
#include <vector>
#include <map>




/*! \brief Specific shape function implementation on basis of polynomials.
* 
* Currently only works for 2D linear polys.
 */
class PolynomialShapeFunction : public ShapeFunction
{
    
public:   
    /*! \brief constructor
    *
    * takes the dimension in which we are operating, the polynomial degree, which is checked against the number of nodes in node1 and node0 together.
    * Constructs a polynom of degree 'degree' in 'dimension' dimensions
    * Setus up the shape functions on the unit element (which depends on dimension).
    * */
    PolynomialShapeFunction(int dimension, int degree);
    
    
    virtual ~PolynomialShapeFunction() {}
    
    /*! \brief Evaluation of shape function number 'id' at point 'x'
    */
    virtual double Eval (int id, const Node& x) const;
    /*! \brief Evaluation of the derivative (with respect to all variables) of shape functions 'id' at point 'x'
    */
    virtual Vector<double> DEval(int id, const Node& x) const;
    virtual int GetNrShapeFunctions() const;
    
private:
    std::vector<Polynomial> polys;
};


#endif /*POLYNOMIALSHAPEFUNCTION_H */
