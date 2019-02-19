#include "ConstantIntegrator.h"

#include <iostream>

//#define DEBUG

double ConstantIntegrator::Integrate(const Simplex * const s, const EnergyFunction* const e, const ShapeFunction* const shape, int nodeid1, int nodeid2) const
{
    //Get volume and midpoint of the simplex, return the energy function evaluated at the shape function at the midpoint. 
    
    double dV = s->GetArea();
#ifdef DEBUG
    std::cout << "Simplex area = " << dV << std::endl;
#endif
    
    //Get centroid of the Simplex
    
    //compute the shape function for the given simplex
    
    
    //ATTENTION: for this version I assume that all the elements look the same like the unit element. In a proper version, this should not be the case. We would need to compute the right evalutaiton points for the energy and the 'shifted' shape functions since the shape function we get is the prototype on the unit element.
    
    int localid1 = s->GetLocalNodeId(nodeid1);
    int localid2 = s->GetLocalNodeId(nodeid2);
    Node x(0, 0);
    
    if (localid1 == -1 || localid2 == -1)
    {
        std::cout << "nodeid1 = " << nodeid1 << "\tnodeid2 = " << nodeid2 << std::endl;
        std::cout << *s << std::endl;
        throw std::invalid_argument("The given node ids are not part of the given simplex in ConstantIntegrator::Integrate");
    }
    //Evaluate EnergyFunction at the centroid.    
    double energy = e->Eval(x, shape, localid1, localid2);
#ifdef DEBUG
    std::cout << "simplex energy " << energy << std::endl;
#endif
    
    
    return dV*energy;
}
