#include "Edge.h"

#include <ostream>

std::ostream& operator<<(std::ostream& os, const Edge& e)
{
    os << e.GetPoint(0) << "," << e.GetPoint(1);
    
    return os;
}
