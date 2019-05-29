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
    /*! \brief Constructor. Doing nothing.
    * 
    */
    ConstantIntegrator() {}
    
    /*! \brief Destructor. Doing nothing.
    * 
    */
    virtual ~ConstantIntegrator() {}
    
    /*! \brief Integrate a given energy function, which takes the shape function, over the given element.
    * 
    * \param[in] s element over which we integrate.
    * \param[in] e energy function over which we integrate.
    * \param[in] shape shape function (=ansatz function) we use. 
    * \return A matrix where each entry represents the integral of each base function against each base function.
    */
    virtual Matrix<double> Integrate(const Element * const s, const EnergyFunction* const e, const ShapeFunction* const shape) const;
    
};



#endif /* CONSTANTINTEGRATOR_H */
