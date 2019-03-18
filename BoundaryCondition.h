#ifndef BOUNDARYCONDITION_H
#define BOUNDARYCONDITION_H


#include "Node.h"

/*! \brief Class representing the boundary condition.
 *
 *  Class representing the boundary condition. Stores information about the type (Neumann 
 *  oder Dirichlet) and lets the function be evaluated. How to use this i NOT part of this class.
 */
class BoundaryCondition
{
public:
    enum Type
    {
        Dirichlet = 0,
        Neumann = 1
    };

    BoundaryCondition(Type type);
    virtual ~BoundaryCondition();

    Type GetType() const {return bc_type_;}

    virtual double Eval(const Node& x) const = 0;

protected:
    Type bc_type_;


};


#endif /* BOUNDARYCONDITION_H */