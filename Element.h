#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <ostream>
#include "Node.h"
#include "Edge.h"

/*! \brief Class representing an element in the mesh.
 *
 *  2D implementation. Consists of nodes and edges and a type indicating if it is a simplex, quad, etc.
 */
class Element
{
public:
    enum Type
    {
        Simplex = 1,
        Quad = 2        
    };
    
public:
    Element(Type t);
    Element(Type t, std::vector<Node*>& nodes, std::vector<Edge*>& edges);
    virtual ~Element();
    
    Type GetType() const {return type_;}
    
    Node* GetNode(int i) {return nodes_[i]; }
    const Node* const GetNode(int i) const {return nodes_[i];}
    
    Edge* GetEdge(int i) {return edges_[i];}
    const Edge* const GetEdge(int i) const {return edges_[i];}
    
    std::vector<Node*>& GetNodes() {return nodes_;}
    std::vector<Edge*>& GetEdges() {return edges_;}
    
    const std::vector<Node*>& GetNodes() const {return nodes_;}
    const std::vector<Edge*>& GetEdges() const {return edges_;}
    
    //Returns the position of the node in the vector pts_.
    //Returns -1 if the given node is not in this simplex
    int GetLocalNodeId(const Node* const node) const;
    
    Node GetCentroid() const;
    
    virtual double GetArea() const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Element& e);
    
    
protected:
    virtual bool IsNondegenerate() const = 0;
    virtual std::ostream& Dump(std::ostream& os) const = 0; 
       
protected:
    Type type_;
    std::vector<Node*> nodes_;
    std::vector<Edge*> edges_;
    
    
    
    
};




#endif /* ELEMENT_H */
