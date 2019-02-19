#ifndef INTEGRATOR_H
#define INTEGRATOR_H


#include "Simplex.h"
#include "EnergyFunction.h"
#include "ShapeFunction.h"
#include "Mesh.h"


class Integrator
{
public:
    Integrator(const Mesh* const mesh);

    virtual ~Integrator();
    
    //integrates the EnergyFunction evaluated at the given ShapeFunction attached to nodeid1 and nodeid2 (global mesh ids) over the given Simplex.
    virtual double Integrate(const Simplex * const s, const EnergyFunction* const e, const ShapeFunction* const shape, int nodeid1, int nodeid2) const = 0;
    
protected:
    const Mesh* const mesh_;
};

#endif /* INTEGRATOR_H */
