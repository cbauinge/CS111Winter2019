#include "Simplex.h"

#include <ostream>
#include <stdexcept>

Simplex::Simplex(std::vector<Node*>& nodes, std::vector<Edge*>& edges, double area = 0) :
    Element(Element::Type::Simplex, nodes, edges), area_(area)
{
    if (!IsNondegenerate())
        throw std::invalid_argument("Simplex is degenerate");
}


bool Simplex::IsNondegenerate() const
{
    if (nodes_.size() != 3)
        return false;
    if (area_ == 0)
        return false;
    
    if (nodes_[0] == nodes_[1] || nodes_[0] == nodes_[2] || nodes_[1] == nodes_[2])
        return false;
    
    //NOTE: there are more cases which i dont cover here. Like if they all lie on a single line etc...
    
    return true;
}



std::ostream& Simplex::Dump(std::ostream& os) const
{
    os << *GetNode(0) << "," << *GetNode(1) << "," << *GetNode(2)
        << "," << *GetEdge(0) << "," << *GetEdge(1) << "," << *GetEdge(2) 
        << "," << GetArea();
        
    return os;
}
