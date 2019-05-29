#include "Node.h"

#include <ostream>

std::ostream& operator<<(std::ostream& os, const Node& n)
{
    os << n.GetX() << "," << n.GetY();
    
    return os;
}


Node Node::operator+(const Node& rhs) const
{
    Node val(x_+rhs.GetX(), y_+rhs.GetY());
    return val;
}


Node& Node::operator+=(const Node& rhs)
{
    x_ += rhs.GetX();
    y_ += rhs.GetY();
    
    return *this;
}


Node Node::operator/(double rhs) const
{
    Node val(x_/rhs, y_/rhs);
    return val;
}


Node& Node::operator/=(double rhs)
{
    x_ /= rhs;
    y_ /= rhs;
    
    return *this;
}


bool Node::operator==(const Node& rhs) const
{
    return rhs.GetX() == x_ && rhs.GetY() == y_;
}


bool Node::operator!= (const Node& rhs) const
{
    return !(*this == rhs);
}
