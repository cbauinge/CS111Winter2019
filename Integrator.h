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
    
    virtual double Integrate(const Simplex * const s, const EnergyFunction* const e, const ShapeFunction* const shape) const = 0;
    
protected:
    const Mesh* const mesh_;
};

#endif /* INTEGRATOR_H */
