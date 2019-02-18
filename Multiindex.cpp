#include "Multiindex.h"
#include <stdexcept>
#include <iostream>


int Multiindex::abs() const
{
    std::cout << "Multiindex abs not implemented" << std::endl;
    return 0;
}


int& Multiindex::operator[] (unsigned int index)
{
    if (index >= values.size())
        throw std::out_of_range("Index out of bounds in Multiindex::operator[]");
    
    return values[index];
}
