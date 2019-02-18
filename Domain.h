#ifndef DOMAIN_H
#define DOMAIN_H


#include "Mesh.h"
#include "Integrator.h"
#include "EnergyFunction.h"
#include "ShapeFunction.h"

class Domain
{
public:
    Domain(Mesh const * const  mesh);
    ~Domain();
    
    const Mesh * const GetMesh() const {return mesh_;}
    
    void SetIntegrator(const Integrator* i) {integrator = i;}
    void SetEnergyFunction(const EnergyFunction* e) {energyfunction = e;}
    void SetShapeFunction(const ShapeFunction* s) {shapefunction = s;}
    
    const Integrator* const GetIntegrator() const {return integrator;}
    const EnergyFunction* const GetEnergyFunction() const {return energyfunction;}
    const ShapeFunction* const GetShapeFunction() const {return shapefunction;}
    
private:
    const Mesh * const mesh_; 
    
    const Integrator* integrator;
    const EnergyFunction* energyfunction;
    const ShapeFunction* shapefunction;
};
    
#endif /*DOMAIN_H*/
