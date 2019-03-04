#include "LaplaceEnergyFunction.h"
#include "Node.h"

#include <iostream>

//#define DEBUG



Matrix<double> LaplaceEnergyFunction::Eval (const Node& x, const ShapeFunction* s, const Element* element) const
{
    Matrix<double> De(s->GetNrShapeFunctions(), s->GetNrShapeFunctions());

    Matrix<double> J = s->GetJacobian(x, element);
    Matrix<double> Jinv = Matrix<double>::Inverse(J);
    
    for (int i = 0; i < s->GetNrShapeFunctions(); i++)
    {
        for (int j = 0; j < s->GetNrShapeFunctions(); j++)
        {
            Vector<double> di = s->DEval(i,x);
            Vector<double> dj = s->DEval(j,x);  
            De[i][j] = Vector<double>::Dot(di, dj); //Gradient*Gradient
        }
    }
    
    return De;
}
