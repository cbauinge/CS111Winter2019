#include "ShapeFunction.h"


Matrix<double> ShapeFunction::DEval(const Node& x) const
{
    Matrix<double> val(x.Dimension(), GetNrShapeFunctions());
    for (int j = 0; j < GetNrShapeFunctions(); j++)
    {
        Vector<double> d = DEval(j, x);
        for (int i = 0; i < d.GetDimension(); i++)
        {
            val[i][j] = d[i];
        }
    }
    return val;
}


Matrix<double> ShapeFunction::GetJacobian(const Node& x, const Element* const elem) const
{
    Matrix<double> J(x.Dimension(), x.Dimension());

    Matrix<double> D = DEval(x);

    for (int i = 0; i < x.Dimension(); i++)
    {
        for (int j = 0; j < x.Dimension(); j++)
        {
            double sum = 0.0;
            for (int a = 0; a < GetNrShapeFunctions(); a++)
            {
                sum += (*elem->GetNode(a))[i]*D[j][a];
            }
            J[i][j] = sum;
        }
    }

    return J;
}