#ifndef LAPLACEENERGYFUNCTION_H
#define LAPLACEENERGYFUNCTION_H


#include "EnergyFunction.h"
#include "Node.h"


class LaplaceEnergyFunction : public EnergyFunction
{
public:
    LaplaceEnergyFunction() {}
    
    virtual ~LaplaceEnergyFunction() {}
    
    virtual double Eval(const Node& x, const ShapeFunction* s, int localid1, int localid2) const;
    
    
    
    
private:
    
};

#endif /*LAPLACEENERGYFUNCTION_H*/
