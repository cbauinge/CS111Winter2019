#ifndef EDGE_H
#define EDGE_H

#include <ostream>

class Edge
{
public:
    Edge(int p1, int p2) : p1_(p1), p2_(p2) {}
    Edge() : Edge(0, 0) {}
    
    int GetNode(int id) const {return id == 0 ? p1_ : p2_;} 
    
    //friend std::ostream& operator<<(std::ostream& os, const Edge& e);
    
private:
    int p1_;
    int p2_;
    
    
};


std::ostream& operator<<(std::ostream& os, const Edge& e);




#endif /* EDGE_H */
