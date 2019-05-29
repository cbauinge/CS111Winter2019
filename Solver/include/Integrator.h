#ifndef INTEGRATOR_H
#define INTEGRATOR_H


#include "Element.h"
#include "EnergyFunction.h"
#include "ShapeFunction.h"
#include "Mesh.h"
#include "Vector.h"

/*! \brief Abstract class representing the integration scheme.
 *
 *  The specific integraiton schemes are derived classed from this class.
 */
class Integrator
{
public:
    Integrator();

    virtual ~Integrator();
    
    /*! \brief integrates the EnergyFunction evaluated the shape function
    */
    virtual Matrix<double> Integrate(const Element * const s, const EnergyFunction* const e, const ShapeFunction* const shape) const = 0;
    
protected:
};

#endif /* INTEGRATOR_H */
