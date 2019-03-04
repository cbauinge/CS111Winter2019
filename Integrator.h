#ifndef INTEGRATOR_H
#define INTEGRATOR_H


#include "Element.h"
#include "EnergyFunction.h"
#include "ShapeFunction.h"
#include "Mesh.h"
#include "Vector.h"


class Integrator
{
public:
    Integrator(const Mesh* const mesh);

    virtual ~Integrator();
    
    //integrates the EnergyFunction evaluated the shape function
    virtual Matrix<double> Integrate(const Element * const s, const EnergyFunction* const e, const ShapeFunction* const shape) const = 0;
    
protected:
    const Mesh* const mesh_;
};

#endif /* INTEGRATOR_H */
