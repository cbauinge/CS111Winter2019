#include "Polynomial.h"
#include <iostream>


Polynomial Polynomial::Derivative(int variable) const
{
    Polynomial poly;
    std::cout << "derivative method in polynomial not implemented" << std::endl;
    return poly;
}

double Polynomial::operator() (const Node& x) const
{
    std::cout << "Polynomial::operator() not implemented" << std::endl;
    return 0;
}
