#ifndef LAPLACEENERGYFUNCTION_H
#define LAPLACEENERGYFUNCTION_H


#include "EnergyFunction.h"
#include "Node.h"


class LaplaceEnergyFunction : public EnergyFunction
{
public:
    LaplaceEnergyFunction() {}
    
    virtual ~LaplaceEnergyFunction() {}
    
    virtual double operator()(const Node& x) const;
    
    
    
    
private:
    
};

#endif /*LAPLACEENERGYFUNCTION_H*/
