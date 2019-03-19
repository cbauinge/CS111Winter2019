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
    /*! \brief Constructor. Takes and energy function and a source function and stores them.
    *
    */
    Equation(EnergyFunction* e, SourceFunction* s);
    /*! \brief Destructor. Deletes energyfct and sourcefct.
    *
    */
    virtual ~Equation();

    /*! \brief Getter for the energy function.
    */
    const EnergyFunction* const GetEnergyFunction() const {return energyfct;}
    /*! \brief Getter for the source function.
    */
    const SourceFunction* const GetSourceFunction() const {return sourcefct;}

private:
    EnergyFunction* energyfct;
    SourceFunction* sourcefct;
};




#endif /* EQUATION_H */