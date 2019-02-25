#include "Writer.h"
#include <iostream>
#include <fstream>
#include "Element.h"



Writer::Writer()
{
}



int Writer::WriteSolution(const Mesh* const mesh, const double * const u, unsigned n, const char* name, const char* path, EFormat format) const
{
    if (format == EFormat::CSV)
    {
        if (mesh->GetInnerNodeIds().size() != n)
            std::cout << "got a dimension problem. Number of values does not fit with number of points." << std::endl;
        else
        {
            WriteMesh(mesh, name, path, format);
            
            std::ofstream ofs((std::string(path) + std::string("/") + std::string("solution_")+std::string(name)).c_str(), std::ofstream::out);
            if (ofs.is_open())
            {
                for (unsigned i = 0; i < n; i++)
                {
                    ofs << u[i];
                    if (i < n-1)
                        ofs << std::endl;
                }
                ofs.close();
            }
            else
                return 1;
        }
    }
    else
        std::cout << "Other formats are not possible yet." << std::endl;
    
    
    return 0;
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
