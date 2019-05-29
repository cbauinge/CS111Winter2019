#include "ConstantIntegrator.h"

#include <iostream>
#include "Matrix.h"

//#define DEBUG

Matrix<double> ConstantIntegrator::Integrate(const Element * const elem, const EnergyFunction* const energy, const ShapeFunction* const shape) const
{ 
    double dV = elem->GetArea();
    Node centroid(1.0/3.0, 1.0/3.0);
    Matrix<double> EnergyEval = energy->Eval(centroid, shape, elem);

    return EnergyEval*dV;
}
