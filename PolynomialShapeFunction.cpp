#include <iostream>
#include <stdexcept>
#include "PolynomialShapeFunction.h"
#include "Polynomial.h"

//#define DEBUG

PolynomialShapeFunction::PolynomialShapeFunction(int dimension, int degree)
{
    //We construct shape functions for the unit simplex here
    
    //we only implement this for dimension = 2 and degree = 1
    if (dimension == 2)
    {
        //linear ansatz functions
        if (degree == 1)
        {
            {
                //1 -x1 -x2
                Polynomial p(2, 1);
                std::vector<int> p0 = {0, 0};                p.GetCoefficients()[Multiindex(p0)] = 1.0;
                std::vector<int> p1 = {1, 0}; 
                p.GetCoefficients()[Multiindex(p1)] = -1.0;
                std::vector<int> p2 = {0, 1}; 
                p.GetCoefficients()[Multiindex(p2)] = -1.0;
                
                polys.push_back(p);
            }
            
            {
                //x1
                Polynomial p(2, 1);
                std::vector<int> p1 = {1, 0};
                p.GetCoefficients()[Multiindex(p1)] = 1.0;
                
                polys.push_back(p);
            }
            
            {
                //x2
                Polynomial p(2, 1);
                std::vector<int> p2 = {0, 1};
                p.GetCoefficients()[Multiindex(p2)] = 1.0;
                
                polys.push_back(p);
            }
        }
        else
            std::cout << "Higher order elements not yet implemented in PolynomialShapeFunction constructor" << std::endl;
        
    }
    else
    {
        std::cout << "Higher dimensions not yet implemented in PolynomialShapeFunction constructor" << std::endl;
    }
    
}


double PolynomialShapeFunction::Eval (int id, const Node& x) const
{
    if (id >= polys.size())
        throw std::invalid_argument("PolynomialShapeFunction::Eval id out of bounds");
    return polys[id](x);
}


std::vector<double> PolynomialShapeFunction::DEval(int id, const Node& x) const
{
    if (id >= polys.size())
        throw std::invalid_argument("PolynomialShapeFunction::Eval id out of bounds");
    
    std::vector<double> dvals;
    
    for (int i = 0; i < polys[id].GetDimension(); i++) {
        Polynomial dp = polys[id].Derivative(i);
        double dpval = dp(x);
#ifdef DEBUG
        std::cout << "DPoly = " << dp << std::endl;
        std::cout << "dval = " << dpval << std::endl;
#endif
        dvals.push_back(dpval);
    }
        
        
    return dvals;
}
