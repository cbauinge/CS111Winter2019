#ifndef EDGE_H
#define EDGE_H

#include <ostream>
#include "Node.h"



/*! \brief Class representing an edge in an element.
 *
 *  Consists of 2 nodes.
 */
class Edge
{
public:
    Edge(Node* n1, Node* n2) : n1_(n1), n2_(n2) {}
    
    const Node* const GetNode(int id) const {return id == 0 ? n1_ : n2_;} 
    Node* GetNode(int id) {return id == 0 ? n1_ : n2_;} 
    
    //friend std::ostream& operator<<(std::ostream& os, const Edge& e);
    
private:
    Node* n1_;
    Node* n2_;
    
    
};


std::ostream& operator<<(std::ostream& os, const Edge& e);




#endif /* EDGE_H */
