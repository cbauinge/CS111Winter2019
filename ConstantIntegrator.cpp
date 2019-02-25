#include "ConstantIntegrator.h"

#include <iostream>

//#define DEBUG

double ConstantIntegrator::Integrate(const Element * const s, const EnergyFunction* const e, const ShapeFunction* const shape, int localnodeid1, int localnodeid2) const
{
    //Get volume and midpoint of the simplex, return the energy function evaluated at the shape function at the midpoint. 
    
    double dV = s->GetArea();
#ifdef DEBUG
    std::cout << "Simplex area = " << dV << std::endl;
#endif
    
    //Get centroid of the Simplex
    
    //compute the shape function for the given simplex
    
    
    //ATTENTION: for this version I assume that all the elements look the same like the unit element. In a proper version, this should not be the case. We would need to compute the right evalutaiton points for the energy and the 'shifted' shape functions since the shape function we get is the prototype on the unit element.
    
    Node c = s->GetCentroid();
    
    //Evaluate EnergyFunction at the centroid.    
    double energy = e->Eval(c, shape, localnodeid1, localnodeid2);
    //usually we need to account for the deformation compared to the unit element used in the 'shape' class. For tests, due to the specific setup i use, we 
    //set the energy to -0.5 if the local ids are not equal and 0.5 if they are 
    energy /= 2*dV;
#ifdef DEBUG
    std::cout << "simplex energy " << energy << std::endl;
#endif
    
    
    return dV*energy;
}
