#ifndef BOUNDARYCONDITION_H
#define BOUNDARYCONDITION_H


#include "Node.h"


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