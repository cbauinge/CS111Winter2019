#include "Writer.h"
#include <iostream>
#include <fstream>



Writer::Writer()
{
}



int Writer::WriteSolution(const Mesh* const mesh, const double * const u, unsigned n, const char* name, EFormat format) const
{
    if (format == EFormat::CSV)
    {
        if (mesh->GetInnerNodeIds().size() != n)
            std::cout << "got a dimension problem. Number of values does not fit with number of points." << std::endl;
        else
        {
            WriteMesh(mesh, name, format);
            
            std::ofstream ofs((std::string("solution_")+std::string(name)).c_str(), std::ofstream::out);
            if (ofs.is_open())
            {
                for (unsigned i = 0; i < n; i++)
                {
                    ofs << u[i] << std::endl;
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


int Writer::WriteNodes(std::vector<const Node*> coordinates, const char* name, EFormat format) const
{
    WritepArray<Node>(coordinates, (std::string("nodes_")+std::string(name)).c_str(), format);
    /*if (format == EFormat::CSV)
    {
        std::ofstream ofs((std::string("nodes_") + std::string(name)).c_str(), std::ofstream::out);
        if (ofs.is_open())
        {
            for (unsigned i = 0; i < coordinates.size(); i++)
            {
                ofs << coordinates[i] << std::endl;
            }
            ofs.close();
        }
        else
            return 1;
    }
    else
        std::cout << "Other formats are not possible yet." << std::endl;
    
    
    std::cout << "Successfully wrote mesh to " << std::string(name) << std::endl;*/
    return 0;
}

int Writer::WriteMesh(const Mesh* const mesh, const char* name, EFormat format) const
{
    WriteNodes(mesh->GetpNodes(), name, format);
    WritepArray<Edge>(mesh->GetpEdges(), (std::string("edges_")+std::string(name)).c_str(), format);
    WritepArray<Simplex>(mesh->GetpSimplices(), (std::string("simplices_")+std::string(name)).c_str(), format);
    
    
    return 0;
}
