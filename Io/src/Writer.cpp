#include "Writer.h"
#include <iostream>
#include <fstream>
#include "Element.h"



Writer::Writer()
{
}

int Writer::WriteMesh(const Mesh* const mesh, const char* name, const char* path, EFormat format) const
{
    WritepArray<Node>(mesh->GetpNodes(), (std::string(path) + std::string("/") + std::string("nodes_")+std::string(name)).c_str(), format);    
    WriteVectorArray<int>(mesh->GetEdges2Nodes(), (std::string(path) + std::string("/") + std::string("edges_")+std::string(name)).c_str(), format);
    WriteVectorArray<int>(mesh->GetElements2Nodes(), (std::string(path) + std::string("/") + std::string("simplices_")+std::string(name)).c_str(), format);
    WriteVectorArray<int>(mesh->GetNodes2Edges(), (std::string(path) + std::string("/") + std::string("nodes2edges_")+std::string(name)).c_str(), format);
    WriteVectorArray<int>(mesh->GetNodes2Elements(), (std::string(path) + std::string("/") + std::string("nodes2elements_")+std::string(name)).c_str(), format);
    WriteVectorArray<int>(mesh->GetEdges2Elements(), (std::string(path) + std::string("/") + std::string("edges2elements_")+std::string(name)).c_str(), format);
    WriteVectorArray<int>(mesh->GetNodes2EdgesInnerNodes(), (std::string(path) + std::string("/") + std::string("node2edgesinnernode_")+std::string(name)).c_str(), format);
    
    
    return 0;
}
