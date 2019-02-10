#include "Node.h"

#include <ostream>

std::ostream& operator<<(std::ostream& os, const Node& n)
{
    os << n.GetX() << "," << n.GetY();
    
    return os;
}
