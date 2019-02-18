#ifndef ENERGYFUNCTION_H
#define ENERGYFUNCTION_H

#include "Node.h"


class EnergyFunction
{
public:
    EnergyFunction() {}
    
    virtual ~EnergyFunction() {}
    
    virtual double operator()(const Node& x) const = 0;
    
    
private:
    
};

#endif /* ENERGYFUNCTION_H */
