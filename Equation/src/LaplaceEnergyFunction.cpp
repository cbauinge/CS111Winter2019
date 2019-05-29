#include "LaplaceEnergyFunction.h"
#include "Node.h"

#include <iostream>

//#define DEBUG



Matrix<double> LaplaceEnergyFunction::Eval (const Node& x, const ShapeFunction* s, const Element* element) const
{
    Matrix<double> De(s->GetNrShapeFunctions(), s->GetNrShapeFunctions());

    Matrix<double> J = s->GetJacobian(x, element);
    Matrix<double> JinvT = Matrix<double>::Transpose(Matrix<double>::Inverse(J));
    
    for (int i = 0; i < s->GetNrShapeFunctions(); i++)
    {
        Vector<double> di_hat = s->DEval(i,x); //derivatives of shape function i on the unit element
        Vector<double> di = JinvT*di_hat; //derivative of shape funciton i on element    
        
        for (int j = 0; j < s->GetNrShapeFunctions(); j++)
        {
            Vector<double> dj_hat = s->DEval(j,x);
            Vector<double> dj = JinvT*dj_hat;
            De[i][j] = Vector<double>::Dot(di, dj); //Gradient*Gradient
        }
    }
    
    return De;
}
