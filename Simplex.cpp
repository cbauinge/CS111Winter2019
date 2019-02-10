#include "Simplex.h"

#include <ostream>

std::ostream& operator<<(std::ostream& os, const Simplex& s)
{
    os << s.GetPoint(0) << "," << s.GetPoint(1) << "," << s.GetPoint(2)
        << "," << s.GetEdge(0) << "," << s.GetEdge(1) << "," << s.GetEdge(2) 
        << "," << s.GetArea();
        
    return os;
}
