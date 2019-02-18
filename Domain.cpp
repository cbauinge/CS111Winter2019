#include "Domain.h"


Domain::Domain(Mesh const * const  mesh) : 
    mesh_(mesh), 
    integrator(nullptr), 
    energyfunction(nullptr), 
    shapefunction(nullptr)
{
    
}



Domain::~Domain()
{

}
