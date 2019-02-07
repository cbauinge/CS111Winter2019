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
         
