#ifndef ENERGYFUNCTION_H
#define ENERGYFUNCTION_H

#include "Node.h"
#include "ShapeFunction.h"


class EnergyFunction
{
public:
    EnergyFunction() {}
    
    virtual ~EnergyFunction() {}
    
    //Function that evaluates the energy taking
    //the point where it should be evaluated
    //the shape function
    //the local ids of which shape functions should be evaluated
    virtual double Eval(const Node& x, const ShapeFunction* s, int localid1, int localid2) const = 0;
    
    
private:
    
};

#endif /* ENERGYFUNCTION_H */
