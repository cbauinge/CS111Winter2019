#include "Mesh.h"
#include <iostream>





Mesh::Mesh(std::vector<Node*> nodes, 
         std::vector<Edge*> edges, 
         std::vector<Element*> elements, 
         std::vector<std::vector<int> > node2edge,
         std::vector<std::vector<int> > node2element,
         std::vector<std::vector<int> > edge2element,
         std::vector<int> inner_nodes,
         std::vector<std::vector<int> > node2edgeinnernode) :
    nodes_(nodes), edges_(edges), elements_(elements), node2edge_(node2edge), node2element_(node2element), edge2element_(edge2element), inner_nodes_(inner_nodes), node2edgeinnernode_(node2edgeinnernode)
{}


Mesh::~Mesh()
{
    for (unsigned i = 0; i < nodes_.size(); i++)
        delete nodes_[i];
    
    for (unsigned i = 0; i < edges_.size(); i++)
        delete edges_[i];
    
    for (unsigned i = 0; i < elements_.size(); i++)
        delete elements_[i];
}


int Mesh::GetNodeId(const Node* node) const
{
    for (int i = 0; i < nodes_.size(); i++) {
        if (*node == *nodes_[i]) {
            return i;
        }
    }
        
    
    return -1;            
}


std::vector<const Node*> Mesh::GetpInnerNodes() const
{
    int n = inner_nodes_.size();
    std::vector<const Node*> nodes(n);
    
    for (int i = 0; i < n; i++)
    {
        nodes[i] = nodes_[inner_nodes_[i]];
    }
    
    return nodes;
}

std::vector<const Node*> Mesh::GetpNodes() const
{
    int n = nodes_.size();
    std::vector<const Node*> nodes(n);
    
    for (int i = 0; i < n; i++)
    {
        nodes[i] = nodes_[i];
    }
    
    return nodes;
}

std::vector<const Edge*> Mesh::GetpEdges() const
{
    int n = edges_.size();
    std::vector<const Edge*> edges(n);
    
    for (int i = 0; i < n; i++)
    {
        edges[i] = edges_[i];
    }
    
    return edges;
}

std::vector<const Element*> Mesh::GetpElements() const
{
    int n = elements_.size();
    std::vector<const Element*> elements(n);
    
    for (int i = 0; i < n; i++)
    {
        elements[i] = elements_[i];
    }
    
    return elements;
}


std::vector<std::vector<int> > Mesh::GetEdges2Nodes() const
{
    std::vector<std::vector<int> > val(edges_.size());
    
    for (int i = 0; i < node2edge_.size(); i++)
    {
        for (int j = 0; j < node2edge_[i].size(); j++)
        {
            val[node2edge_[i][j]].push_back(i);
        }
    }
    
    return val;
}


std::vector<std::vector<int> > Mesh::GetElements2Nodes() const
{
    std::vector<std::vector<int> > val(elements_.size());
    
    for (int i = 0; i < node2element_.size(); i++)
    {
        for (int j = 0; j < node2element_[i].size(); j++)
        {
            val[node2element_[i][j]].push_back(i);
        }
    }    
    
    return val;
}



//std::ostream& operator<<(std::ostream& os, const Mesh& m)
//{
    
//}
