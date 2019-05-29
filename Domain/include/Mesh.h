#ifndef MESH_H
#define MESH_H


#include<vector>
#include "Node.h"
#include "Edge.h"
#include "Element.h"

/*! \brief Mesh. Geomtric representation of the domain.
 *
 *  Only holds geometrical data necessary to solve the PDE. No knowledge about the PDE, bc,etc. Is part of the domain.
 */
class Mesh
{
public:
    Mesh() = default;
    
    /*! \brief Constructor. Takes nodes, edges, elements, and all the helper arrays.
    *
    */
    Mesh(std::vector<Node*> nodes, 
         std::vector<Edge*> edges, 
         std::vector<Element*> elements, 
         std::vector<std::vector<int> > node2edge,
         std::vector<std::vector<int> > node2element,
         std::vector<std::vector<int> > edge2element,
         std::vector<int> inner_nodes,
         std::vector<std::vector<int> > node2edgeinnernode);
    
    ~Mesh();
    
    const Node* GetNode(int id) const {return nodes_[id];}
    int GetNodeId(const Node* node) const;
    const Edge* GetEdge(int id) const {return edges_[id];}
    const Element* GetElement(int id) const {return elements_[id];}
    const std::vector<int>& GetEdgesFromNode(int id) const {return node2edge_[id];}
    const std::vector<int>& GetElementsFromNode(int id) const {return node2element_[id];}
    const std::vector<int>& GetElementsFromEdge(int id) const {return edge2element_[id];}
    const std::vector<int>& GetInnerNodeIds() const {return inner_nodes_;}
    std::vector<const Node*> GetpInnerNodes() const;
    std::vector<const Node*> GetpNodes() const;
    int GetNumberNodes() const {return nodes_.size();}
    std::vector<const Edge*> GetpEdges() const;
    std::vector<const Element*> GetpElements() const;
    const std::vector<int>& GetEdgesToInnerNodesFromNode(int id) const {return node2edgeinnernode_[id];}
    
    std::vector<std::vector<int> > GetEdges2Nodes() const;
    std::vector<std::vector<int> > GetElements2Nodes() const;
    const std::vector<std::vector<int> >& GetNodes2Edges() const {return node2edge_;}
    const std::vector<std::vector<int> >& GetNodes2Elements() const {return node2element_;}
    const std::vector<std::vector<int> >& GetEdges2Elements() const {return edge2element_;}
    const std::vector<std::vector<int> >& GetNodes2EdgesInnerNodes() const {return node2edgeinnernode_;}
    
    
    
private:
    std::vector<Node*> nodes_;
    std::vector<Edge*> edges_; 
    std::vector<Element*> elements_; 
    std::vector<std::vector<int> > node2edge_;
    std::vector<std::vector<int> > node2element_;
    std::vector<std::vector<int> > edge2element_;
    std::vector<int> inner_nodes_;
    std::vector<std::vector<int> > node2edgeinnernode_;
};


//std::ostream& operator<<(std::ostream& os, const Mesh& m);

#endif /*MESH_H*/
