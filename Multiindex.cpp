#include "Multiindex.h"
#include <stdexcept>
#include <iostream>
#include <ostream>


int Multiindex::abs() const
{
    int sum = 0;
    
    for (auto val : values)
        sum += val;
    
    return sum;
}


int& Multiindex::operator[] (unsigned int index)
{
    if (index >= size())
        throw std::out_of_range("Index out of bounds in Multiindex::operator[]");
    
    return values[index];
}

int Multiindex::operator[] (unsigned int index) const
{
    if (index >= size())
        throw std::out_of_range("Index out of bounds in Multiindex::operator[]");
    
    return values[index];
}


bool Multiindex::operator < (const Multiindex& m) const 
{
	if (m.size() == size())
    {
        for (int i = 0; i< size(); i++)
        {
            if (values[i] < m[i]) return true;
            if (values[i] > m[i]) return false;
        }
    }
	return false;
}


std::ostream& operator<<(std::ostream& ofs, const Multiindex& m)
{
    for (int i = 0; i < m.size(); i++)
    {
        ofs << m[i];
        if (i < m.size() -1)
            ofs << ", ";
    }
    
    return ofs;
}
