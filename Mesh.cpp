#include "Mesh.h"
#include <iostream>





Mesh::Mesh(std::vector<Node> nodes, 
    std::vector<Edge> edges, 
    std::vector<Simplex> simplices, 
    std::vector<std::vector<int> > node2edge,
    std::vector<std::vector<int> > node2simplex,
    std::vector<std::vector<int> > edge2simplex,
    std::vector<int> inner_nodes,
    std::vector<std::vector<int> > node2edgeinnernode) :
    nodes_(nodes), edges_(edges), simplices_(simplices), node2edge_(node2edge), node2simplex_(node2simplex), edge2simplex_(edge2simplex), inner_nodes_(inner_nodes), node2edgeinnernode_(node2edgeinnernode)
{}


std::vector<const Node*> Mesh::GetpInnerNodes() const
{
    int n = inner_nodes_.size();
    std::vector<const Node*> nodes(n);
    
    for (int i = 0; i < n; i++)
    {
        nodes[i] = &nodes_[inner_nodes_[i]];
    }
    
    return nodes;
}

std::vector<const Node*> Mesh::GetpNodes() const
{
    int n = nodes_.size();
    std::vector<const Node*> nodes(n);
    
    for (int i = 0; i < n; i++)
    {
        nodes[i] = &nodes_[i];
    }
    
    return nodes;
}

std::vector<const Edge*> Mesh::GetpEdges() const
{
    int n = edges_.size();
    std::vector<const Edge*> edges(n);
    
    for (int i = 0; i < n; i++)
    {
        edges[i] = &edges_[i];
    }
    
    return edges;
}

std::vector<const Simplex*> Mesh::GetpSimplices() const
{
    int n = simplices_.size();
    std::vector<const Simplex*> simplices(n);
    
    for (int i = 0; i < n; i++)
    {
        simplices[i] = &simplices_[i];
    }
    
    return simplices;
}



//std::ostream& operator<<(std::ostream& os, const Mesh& m)
//{
    
//}
