#ifndef EQUATION_H
#define EQUATION_H

#include "EnergyFunction.h"
#include "SourceFunction.h"

/*! \brief Class representing the PDE to solve.
 *
 *  Consists of an energy function (which is the lhs in the variational formulation) and the source fct (f in the rhs of the variational formulation)
 */
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