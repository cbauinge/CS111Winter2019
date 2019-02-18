#include "LaplaceEnergyFunction.h"
#include "Node.h"

#include <iostream>


double LaplaceEnergyFunction::operator() (const Node& x) const
{
    std::cout << "Laplace energy function evaluation operator not defined yet" << std::endl;
    return 0;
}
