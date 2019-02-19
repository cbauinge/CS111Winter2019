#include "LaplaceEnergyFunction.h"
#include "Node.h"

#include <iostream>

//#define DEBUG



double LaplaceEnergyFunction::Eval (const Node& x, const ShapeFunction* s, int localid1, int localid2) const
{
    std::vector<double> d1 = s->DEval(localid1, x);
    std::vector<double> d2 = s->DEval(localid2, x);
    
    double sum = 0.0;
    
    for (int i = 0; i < d1.size(); i++)
    {
#ifdef DEBUG
        std::cout << "d1[i], d2[i] =" <<  d1[i] << ", " <<d2[i] << std::endl;
#endif
        sum += d1[i]*d2[i];
    }
    
    return sum;
}
