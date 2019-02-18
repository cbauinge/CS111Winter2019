#ifndef CONSTANTINTEGRATOR_H
#define CONSTANTINTEGRATOR_H


#include "Integrator.h"

#include "Simplex.h"
#include "EnergyFunction.h"
#include "ShapeFunction.h"

#include "Mesh.h"

class ConstantIntegrator : public Integrator
{
public:
    ConstantIntegrator(const Mesh* const mesh) : Integrator(mesh) {}
    
    virtual ~ConstantIntegrator() {}
    
    
    double Integrate(const Simplex * const s, const EnergyFunction* const e, const ShapeFunction* const shape) const;
    
};



#endif /* CONSTANTINTEGRATOR_H */
