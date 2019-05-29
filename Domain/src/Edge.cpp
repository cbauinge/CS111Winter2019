#include "Edge.h"

#include <ostream>

std::ostream& operator<<(std::ostream& os, const Edge& e)
{
    os << *e.GetNode(0) << "," << *e.GetNode(1);
    
    return os;
}
