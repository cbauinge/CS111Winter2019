#ifndef LAPLACEENERGYFUNCTION_H
#define LAPLACEENERGYFUNCTION_H


#include "EnergyFunction.h"
#include "Node.h"
#include "Matrix.h"

/*! \brief Specific energy function for the Laplace equation.
 *
 *  Derived class from EnergyFunction
 */
class LaplaceEnergyFunction : public EnergyFunction
{
public:
    LaplaceEnergyFunction() {}
    
    virtual ~LaplaceEnergyFunction() {}
    
    /* @see EnergyFunction
    */
    virtual Matrix<double> Eval(const Node& x, const ShapeFunction* s, const Element* element) const;
    
    
    
    
private:
    
};

#endif /*LAPLACEENERGYFUNCTION_H*/
