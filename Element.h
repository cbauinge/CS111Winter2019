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
    /*! \brief Enum describing the type of the element (simplex, quad, diamond, etc.)
    */
    enum Type
    {
        Simplex = 1,
        Quad = 2        
    };
    
public:
    /*! \brief Constructor. Takes the Type and stores it.
    */
    Element(Type t);
    /*! \brief Constructor. Takes the Type nodes and edges of the element and stores them.
    */
    Element(Type t, std::vector<Node*>& nodes, std::vector<Edge*>& edges);
    /*! \brief Destructor. Doing nothing.
    */
    virtual ~Element();
    
    /*! \brief Getter for the type.
    */
    Type GetType() const {return type_;}
    
    /*! \brief Getter for the node.
    *
    * \param[in] i Id of the node we want to get.
    * \return Pointer to the node with the geiven id.
    */
    Node* GetNode(int i) {return nodes_[i]; }
    const Node* const GetNode(int i) const {return nodes_[i];}
    
    /*! \brief Getter for the edge.
    *
    * \param[in] i Id of the edge we want to get.
    * \return Pointer to the edge with the geiven id.
    */
    Edge* GetEdge(int i) {return edges_[i];}
    const Edge* const GetEdge(int i) const {return edges_[i];}
    
    /*! \brief Getter all nodes.
    */
    std::vector<Node*>& GetNodes() {return nodes_;}
    /*! \brief Getter all edges.
    */
    std::vector<Edge*>& GetEdges() {return edges_;}
    
    const std::vector<Node*>& GetNodes() const {return nodes_;}
    const std::vector<Edge*>& GetEdges() const {return edges_;}
    
    /*! \brief Converts a node to the local node id.
    *
    * \param[in] node Pointer to a node.
    * /return The id of the given node in this element. Returns -1 if the node is not part of the element.
    */
    int GetLocalNodeId(const Node* const node) const;
    
    /*! \brief Compute and return the centroid.
    */
    Node GetCentroid() const;
    
    /*! \brief Compute and return the area of this element.
    */
    virtual double GetArea() const = 0;
    
    /*! \brief Overloaded output operator.
    */
    friend std::ostream& operator<<(std::ostream& os, const Element& e);
    
    
protected:
    /*! \brief Function that checks if the element is not degenerate.
    */
    virtual bool IsNondegenerate() const = 0;
    /*! \brief Dump function.
    */
    virtual std::ostream& Dump(std::ostream& os) const = 0; 
       
protected:
    Type type_;
    std::vector<Node*> nodes_;
    std::vector<Edge*> edges_;
    
    
    
    
};




#endif /* ELEMENT_H */
