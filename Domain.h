#ifndef DOMAIN_H
#define DOMAIN_H


#include "Mesh.h"
#include "Integrator.h"
#include "Equation.h"
#include "ShapeFunction.h"

class Domain
{
public:
    Domain(Mesh const * const  mesh);
    ~Domain();
    
    const Mesh * const GetMesh() const {return mesh_;}
    
    void SetIntegrator(const Integrator* i) {integrator = i;}
    void SetEquation(const Equation* e) {equation = e;}
    void SetShapeFunction(const ShapeFunction* s) {shapefunction = s;}
    
    const Integrator* const GetIntegrator() const {return integrator;}
    const Equation* const GetEquation() const {return equation;}
    const ShapeFunction* const GetShapeFunction() const {return shapefunction;}
    
private:
    const Mesh * const mesh_; 
    
    const Integrator* integrator;
    const Equation* equation;
    const ShapeFunction* shapefunction;
};
    
#endif /*DOMAIN_H*/
