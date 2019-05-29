#include "Element.h"


Element::Element(Type t) : 
    type_(t)
{
    
}
    
    
Element::Element(Type t, std::vector<Node*>& nodes, std::vector<Edge*>& edges) :
    type_(t), nodes_(nodes), edges_(edges)
{
}        


Element::~Element()
{
}

Node Element::GetCentroid() const
{
    Node val;
    
    for (auto n : nodes_)
        val += *n;
    
    val /= nodes_.size();
    
    return val;
}


int Element::GetLocalNodeId(const Node* const node) const
{
    for (unsigned i = 0; i < nodes_.size(); i++)
    {
        if (*node == *GetNode(i))
            return i;
    }
    
    return -1;
}



std::ostream& operator<<(std::ostream& os, const Element& e)
{
    return e.Dump(os);
}
