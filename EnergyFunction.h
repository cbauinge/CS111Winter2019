#ifndef ENERGYFUNCTION_H
#define ENERGYFUNCTION_H

#include "Node.h"
#include "ShapeFunction.h"
#include "Matrix.h"
#include "Element.h"

/*! \brief Function that represents the differential operator in variational formulation. I.e it takes shape functions and points and evaluates it there.
* 
* Function that represents the differential operator in variational formulation. I.e it takes shape functions and points and evaluates it there.
* Every specfific energy function is a derived class from this class
* Later, the user could add new energy functions using runtime compilation and dynamical linking.
*/
class EnergyFunction
{
  public:
    EnergyFunction() {}

    virtual ~EnergyFunction() {}

    //Function that evaluates the energy taking
    //the point where it should be evaluated
    //the shape function on the unit element s
    //the element on which we evaluate, element
    //returns all possible combinations of ht elocal shape functions plugged into the Energy
    virtual Matrix<double> Eval(const Node &x, const ShapeFunction *s, const Element* element) const = 0;

  private:
};

#endif /* ENERGYFUNCTION_H */
