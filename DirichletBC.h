#ifndef DIRICHLETBC_H
#define DIRICHLETBC_H


#include "BoundaryCondition.h"
#include "Node.h"


class DirichletBC : public BoundaryCondition
{
public:
    DirichletBC();
    ~DirichletBC();

    virtual double Eval(const Node& x) const;
};








#endif /* DIRICHLET_BC */