#include "Simplex.h"

#include <ostream>


int Simplex::GetLocalNodeId(int id) const
{
    for (unsigned i = 0; i < pts_.size(); i++)
    {
        if (id == pts_[i])
            return i;
    }
    
    return -1;
}



std::ostream& operator<<(std::ostream& os, const Simplex& s)
{
    os << s.GetNode(0) << "," << s.GetNode(1) << "," << s.GetNode(2)
        << "," << s.GetEdge(0) << "," << s.GetEdge(1) << "," << s.GetEdge(2) 
        << "," << s.GetArea();
        
    return os;
}
