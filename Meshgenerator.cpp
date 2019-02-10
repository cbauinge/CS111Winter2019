#include "Meshgenerator.h"
#include "Mesh.h"


Meshgenerator::Meshgenerator()
{
    
}


const Mesh* const  Meshgenerator::Generate(int n) const
{
    Mesh* test_mesh = new Mesh;
    
    if (n >= 1)
    {
        double h = 1.0/n;
        std::vector<Node> nodes((n+1)*(n+1)); 
        std::vector<Edge> edges;
        std::vector<Simplex> simplices;
        std::vector<std::vector<int> > node2edge((n+1)*(n+1));
        std::vector<std::vector<int> > node2simplex((n+1)*(n+1));
        std::vector<std::vector<int> > edge2simplex;
        std::vector<int> inner_nodes;
        std::vector<std::vector<int> > node2edgeinnernode((n+1)*(n+1));
        
        //add the first elements here
        
        
        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i <= n; i++)
            {
                int id = i + (n+1)*j;
                nodes[id] = Node(i*h, j*h);
                if (i > 0 && i < n && j > 0 && j < n)
                    inner_nodes.push_back(id);
                
                
                if (i < n) 
                {
                    int nextnodeid = i+1 + (n+1)*j;
                    edges.push_back(Edge(id, nextnodeid));
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
                    edges.push_back(Edge(id, nextnodeid));
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
                    edges.push_back(Edge(id, nextnodeid));
                    node2edge[id].push_back(edges.size() -1);
                    node2edge[nextnodeid].push_back(edges.size() - 1);
                    if (i > 0 && i < n && j+1 > 0 && j+1 < n)
                        node2edgeinnernode[id].push_back(edges.size() - 1);
                    if (i > 0 && i < n && j > 0 && j < n)
                        node2edgeinnernode[nextnodeid].push_back(edges.size() - 1);
                }
            }
        }
        
        edge2simplex.resize(edges.size());
        double area = h*h/2.0;
        
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int id = i + (n+1)*j;
                {
                    std::vector<int> pts = {id, id+1, id+1+n+1};
                    std::vector<int> edges = {node2edge[id][0], node2edge[id+1][2], node2edge[id][1]};
                    simplices.push_back(Simplex(pts, edges, area));
                    int simplex_id = simplices.size()-1;
                    for (int k = 0; k < 3; k++) {
                        node2simplex[pts[k]].push_back(simplex_id);
                        edge2simplex[edges[k]].push_back(simplex_id);
                    }
                }
                
                {
                    std::vector<int> pts = {id, id+1+n+1, id+n+1};
                    std::vector<int> edges = {node2edge[id][1], node2edge[id+n+1][0], node2edge[id][2]};
                    simplices.push_back(Simplex(pts, edges, area));
                    int simplex_id = simplices.size()-1;
                    for (int k = 0; k < 3; k++) {
                        node2simplex[pts[k]].push_back(simplex_id);
                        edge2simplex[edges[k]].push_back(simplex_id);
                    }
                }
            }
        }
        
                
        
        //update the mesh
        delete test_mesh;
        test_mesh = new Mesh(nodes, edges, simplices, node2edge, node2simplex, edge2simplex, inner_nodes, node2edgeinnernode);
    }
    
    return test_mesh;
}
