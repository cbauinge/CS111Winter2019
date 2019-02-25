#include "Polynomial.h"
#include <iostream>
#include <cmath>

//#define DEBUG

Polynomial Polynomial::Derivative(int variable) const
{
    Polynomial dp(dimension, degree-1);
    for (auto iter = coeffs.begin(); iter != coeffs.end(); iter++)
    {
        Multiindex idx = iter->first;
        int idxval = idx[variable];
        if (idxval > 0)
        {
            idx[variable] -= 1;
            dp.GetCoefficients()[idx] = idxval*iter->second;
        }
    }
    
    
    return dp;
}

double Polynomial::operator() (const Node& x) const
{
    double val = 0.0;
#ifdef DEBUG
    std::cout << *this << std::endl;
    std::cout << "val = " << val << std::endl;
#endif
    for (auto iter = coeffs.begin(); iter != coeffs.end(); iter++)
    {
        double term = iter->second;
        for (int i = 0; i < iter->first.size(); i++)
        {
            if (iter->first[i] != 0)
                term *= std::pow(x[i], iter->first[i]);
            
            #ifdef DEBUG
            std::cout << "term = " << term << std::endl;
            #endif
        }
        val += term;
        #ifdef DEBUG
            std::cout << "val = " << val << std::endl;
        #endif
    }
    
    
    return val;
}

std::ostream& operator<<(std::ostream& ofs, const Polynomial& poly)
{
    const std::map<Multiindex, double>& coeffs = poly.GetCoefficients();
    for (auto iter = coeffs.begin(); iter != coeffs.end(); iter++)
    {
        ofs << iter->first << ", value = " << iter->second;
    }
    
    return ofs;
}
