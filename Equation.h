#ifndef EQUATION_H
#define EQUATION_H

#include "EnergyFunction.h"
#include "SourceFunction.h"

class Equation
{
public:
    Equation(EnergyFunction* e, SourceFunction* s);
    virtual ~Equation();

    const EnergyFunction* const GetEnergyFunction() const {return energyfct;}
    const SourceFunction* const GetSourceFunction() const {return sourcefct;}

private:
    EnergyFunction* energyfct;
    SourceFunction* sourcefct;
};




#endif /* EQUATION_H */