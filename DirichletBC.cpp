#include "DirichletBC.h"

#include <cmath>


DirichletBC::DirichletBC() : BoundaryCondition(BoundaryCondition::Type::Dirichlet)
{

}

DirichletBC::~DirichletBC()
{

}

double DirichletBC::Eval(const Node& x) const
{
    return std::sin(2.0*3.14159*x.GetX());
}