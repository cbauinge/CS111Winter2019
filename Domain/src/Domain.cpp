#include "Domain.h"


Domain::Domain(Mesh const * const  mesh) : 
    mesh_(mesh), 
    integrator(nullptr), 
    equation(nullptr), 
    shapefunction(nullptr)
{
    
}



Domain::~Domain()
{
    delete integrator;
    delete equation;
    delete shapefunction;
    delete boundarycondition;
}
