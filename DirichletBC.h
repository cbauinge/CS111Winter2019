#ifndef DIRICHLETBC_H
#define DIRICHLETBC_H


#include "BoundaryCondition.h"
#include "Node.h"

/*! \brief Class representing the dirichlet boundary condition.
 *
 *  Class representing the dirichlet boundary condition. Derived from BoundaryCondition. Automatically sets the type to Dirichlet.
 */
class DirichletBC : public BoundaryCondition
{
public:
    DirichletBC();
    ~DirichletBC();

    virtual double Eval(const Node& x) const;
};








#endif /* DIRICHLET_BC */