#include "Meshgenerator.h"
#include "Mesh.h"

#include "Element.h"
#include "Simplex.h"

#include <iostream>


Meshgenerator::Meshgenerator()
{
    
}


const Mesh* const  Meshgenerator::Generate(int n) const
{
    Mesh* test_mesh = new Mesh;
    
    if (n >= 1)
    {
        double h = 1.0/n;
        std::vector<Node*> nodes((n+1)*(n+1)); 
        std::vector<Edge*> edges;
        std::vector<Element*> elements;
        std::vector<std::vector<int> > node2edge((n+1)*(n+1));
        std::vector<std::vector<int> > node2element((n+1)*(n+1));
        std::vector<std::vector<int> > edge2element;
        std::vector<int> inner_nodes;
        std::vector<std::vector<int> > node2edgeinnernode((n+1)*(n+1));
        
        
        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i <= n; i++)
            {
                int id = i + (n+1)*j;
                nodes[id] = new Node(i*h, j*h);
                if (i > 0 && i < n && j > 0 && j < n)
                    inner_nodes.push_back(id);
            }
        }
        
        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i <= n; i++)
            {
                int id = i + (n+1)*j;
                
                if (i < n) 
                {
                    int nextnodeid = i+1 + (n+1)*j;
                    edges.push_back(new Edge(nodes[id], nodes[nextnodeid]));
                    node2edge[id].push_back(edges.size() - 1);
                    node2edge[nextnodeid].push_back(edges.size() - 1);
                    if (i+1 > 0 && i+1 < n && j > 0 && j < n)
                        node2edgeinnernode[id].push_back(edges.size() - 1);
                    if (i > 0 && i < n && j > 0 && j < n)
                        node2edgeinnernode[nextnodeid].push_back(edges.size() - 1);
                }
                if (i < n && j < n)
                {
                    int nextnodeid = i+1 + (n+1)*(j+1);
                    edges.push_back(new Edge(nodes[id], nodes[nextnodeid]));
                    node2edge[id].push_back(edges.size() -1);
                    node2edge[nextnodeid].push_back(edges.size() - 1);
                    if (i+1 > 0 && i+1 < n && j+1 > 0 && j+1 < n)
                        node2edgeinnernode[id].push_back(edges.size() - 1);
                    if (i > 0 && i < n && j > 0 && j < n)
                        node2edgeinnernode[nextnodeid].push_back(edges.size() - 1);
                }
                if (j < n)
                {
                    int nextnodeid = i + (n+1)*(j+1);
                    edges.push_back(new Edge(nodes[id], nodes[nextnodeid]));
                    node2edge[id].push_back(edges.size() -1);
                    node2edge[nextnodeid].push_back(edges.size() - 1);
                    if (i > 0 && i < n && j+1 > 0 && j+1 < n)
                        node2edgeinnernode[id].push_back(edges.size() - 1);
                    if (i > 0 && i < n && j > 0 && j < n)
                        node2edgeinnernode[nextnodeid].push_back(edges.size() - 1);
                }
            }
        }
        
        edge2element.resize(edges.size());
        double area = h*h/2.0;
        
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int id = i + (n+1)*j;
                {
                    int node1 = id;
                    int node2 = id+1;
                    int node3 = id+n+2;
                    int edge1 = GetEdgeIdFromNodes(nodes[node1], nodes[node2], edges);
                    int edge2 = GetEdgeIdFromNodes(nodes[node1], nodes[node3], edges);
                    int edge3 = GetEdgeIdFromNodes(nodes[node2], nodes[node3], edges);
                    std::vector<Node*> elemnodes = {nodes[node1], nodes[node2], nodes[node3]};
                    std::vector<Edge*> elemedges = {edges[edge1], edges[edge2], edges[edge3]};
                    elements.push_back(new Simplex(elemnodes, elemedges, area));
                    int element_id = elements.size()-1;
                    
                    node2element[node1].push_back(element_id);
                    node2element[node2].push_back(element_id);
                    node2element[node3].push_back(element_id);
                    
                    edge2element[edge1].push_back(element_id);
                    edge2element[edge2].push_back(element_id);
                    edge2element[edge3].push_back(element_id);

                }
                
                {
                    int node1 = id;
                    int node2 = id+1+n+1;
                    int node3 = id+n+1;
                    int edge1 = GetEdgeIdFromNodes(nodes[node1], nodes[node2], edges);
                    int edge2 = GetEdgeIdFromNodes(nodes[node1], nodes[node3], edges);
                    int edge3 = GetEdgeIdFromNodes(nodes[node2], nodes[node3], edges);
                    std::vector<Node*> elemnodes = {nodes[node1], nodes[node2], nodes[node3]};
                    std::vector<Edge*> elemedges = {edges[edge1], edges[edge2], edges[edge3]};
                    elements.push_back(new Simplex(elemnodes, elemedges, area));
                    int element_id = elements.size()-1;
                    
                    node2element[node1].push_back(element_id);
                    node2element[node2].push_back(element_id);
                    node2element[node3].push_back(element_id);
                    
                    edge2element[edge1].push_back(element_id);
                    edge2element[edge2].push_back(element_id);
                    edge2element[edge3].push_back(element_id);
                }
            }
        }
        
                
        
        //update the mesh
        delete test_mesh;
        test_mesh = new Mesh(nodes, edges, elements, node2edge, node2element, edge2element, inner_nodes, node2edgeinnernode);
    }
    
    std::cout << "Finished Generating Mesh" << std::endl;
    
    return test_mesh;
}


int Meshgenerator::GetEdgeIdFromNodes(const Node* node1, const Node* node2, std::vector<Edge*>& edges) const
{
    for (int i = 0; i < edges.size(); i++)
    {
        if ((*node1 == *edges[i]->GetNode(0) && *node2 == *edges[i]->GetNode(1)) ||
            (*node2 == *edges[i]->GetNode(0) && *node1 == *edges[i]->GetNode(1)))
            return i;
    }
    return -1;
}
