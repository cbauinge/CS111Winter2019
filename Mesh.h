#ifndef MESH_H
#define MESH_H


#include<vector>
#include "Node.h"
#include "Edge.h"
#include "Simplex.h"


class Mesh
{
public:
    Mesh() = default;
    
    Mesh(std::vector<Node> nodes, 
         std::vector<Edge> edges, 
         std::vector<Simplex> simplices, 
         std::vector<std::vector<int> > node2edge,
         std::vector<std::vector<int> > node2simplex,
         std::vector<std::vector<int> > edge2simplex,
         std::vector<int> inner_nodes,
         std::vector<std::vector<int> > node2edgeinnernode);
    
    const Node* GetNode(int id) const {return &nodes_[id];}
    const Edge* GetEdge(int id) const {return &edges_[id];}
    const Simplex* GetSimplex(int id) const {return &simplices_[id];}
    const std::vector<int>& GetEdgesFromNode(int id) const {return node2edge_[id];}
    const std::vector<int>& GetSimplicesFromNode(int id) const {return node2simplex_[id];}
    const std::vector<int>& GetSimplicesFromEdge(int id) const {return edge2simplex_[id];}
    const std::vector<int>& GetInnerNodeIds() const {return inner_nodes_;}
    std::vector<const Node*> GetpInnerNodes() const;
    std::vector<const Node*> GetpNodes() const;
    std::vector<const Edge*> GetpEdges() const;
    std::vector<const Simplex*> GetpSimplices() const;
    const std::vector<int>& GetEdgesToInnerNodesFromNode(int id) const {return node2edgeinnernode_[id];}
    
    
private:
    std::vector<Node> nodes_;
    std::vector<Edge> edges_; 
    std::vector<Simplex> simplices_; 
    std::vector<std::vector<int> > node2edge_;
    std::vector<std::vector<int> > node2simplex_;
    std::vector<std::vector<int> > edge2simplex_;
    std::vector<int> inner_nodes_;
    std::vector<std::vector<int> > node2edgeinnernode_;
};


//std::ostream& operator<<(std::ostream& os, const Mesh& m);

#endif /*MESH_H*/
