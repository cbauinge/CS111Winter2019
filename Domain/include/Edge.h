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
    /*! \brief Constructor for the edge. Takes two nodes which define the edge.
    */
    Edge(Node* n1, Node* n2) : n1_(n1), n2_(n2) {}
    
    /*! \brief Getter for the nodes.
    * /param[in] id Id of the node we want to get. 0 is the first one. Everything else the second.
    */
    const Node* const GetNode(int id) const {return id == 0 ? n1_ : n2_;} 
    Node* GetNode(int id) {return id == 0 ? n1_ : n2_;} 
    
    
private:
    Node* n1_;
    Node* n2_;
    
    
};


std::ostream& operator<<(std::ostream& os, const Edge& e);




#endif /* EDGE_H */
