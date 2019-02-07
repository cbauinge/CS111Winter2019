#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    Edge(int p1, int p2) : p1_(p1), p2_(p2) {}
    Edge() : Edge(0, 0) {}
    
    int GetPoint(int id) const {return id == 1 ? p1_ : p2_;} 
    
private:
    int p1_;
    int p2_;
    
    
};





#endif /* EDGE_H */
