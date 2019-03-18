#ifndef CONSTANTINTEGRATOR_H
#define CONSTANTINTEGRATOR_H


#include "Integrator.h"

#include "Element.h"
#include "EnergyFunction.h"
#include "ShapeFunction.h"

#include "Mesh.h"


/*! \brief Class representing a specialized integrator scheme.
 *
 *  Integrator scheme that assumes the values to be constant on an element. I.e. comptutes the value of the function to be integrated
 *  on the centroid of the element and multiplies it with the area/volume of the element.
 */
class ConstantIntegrator : public Integrator
{
public:
    ConstantIntegrator() {}
    
    virtual ~ConstantIntegrator() {}
    
    
    virtual Matrix<double> Integrate(const Element * const s, const EnergyFunction* const e, const ShapeFunction* const shape) const;
    
};



#endif /* CONSTANTINTEGRATOR_H */
