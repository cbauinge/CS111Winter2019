#ifndef WRITER_H
#define WRITER_H

#include "Domain.h"
#include "Mesh.h"
#include <string>
#include <iostream>
#include <ostream>


/*! \brief Class to write output.
 *
 *  
 */
class Writer
{
public:
    enum EFormat
    {
        CSV = 0,
        VTK = 1
    };
    
    Writer();
    
    template <typename T>
    int WriteSolution(const Mesh* const mesh, T u, unsigned n, const char* name, const char* path, EFormat format) const
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
    int WriteMesh(const Mesh* const mesh, const char* name, const char* path, EFormat format) const;
    
    template<typename T>
    int WritepArray(std::vector<const T*> v, const char* name, EFormat format) const
    {
        if (format == EFormat::CSV)
        {
            std::ofstream ofs(name, std::ofstream::out);
            if (ofs.is_open())
            {
                for (unsigned i = 0; i < v.size(); i++)
                {
                    ofs << *v[i] << std::endl;
                }
                ofs.close();
            }
            else
                return 1;
        }
        else
            std::cout << "Other formats are not possible yet." << std::endl;
        
        
        //std::cout << "Successfully wrote array with " << v.size() << " elements to " << std::string(name) << std::endl;
        return 0;
    }
    
    template<typename T>
    int WriteArray(std::vector<const T> v, const char* name, EFormat format) const
    {
        if (format == EFormat::CSV)
        {
            std::ofstream ofs(name, std::ofstream::out);
            if (ofs.is_open())
            {
                for (unsigned i = 0; i < v.size(); i++)
                {
                    ofs << v[i] << std::endl;
                }
                ofs.close();
            }
            else
                return 1;
        }
        else
            std::cout << "Other formats are not possible yet." << std::endl;
        
        
        //std::cout << "Successfully wrote array with " << v.size() << " elements to " << std::string(name) << std::endl;
        return 0;
    }
    
    template<typename T>
    int WriteVectorArray(std::vector<std::vector<T> > v, const char* name, EFormat format) const
    {
        if (format == EFormat::CSV)
        {
            std::ofstream ofs(name, std::ofstream::out);
            if (ofs.is_open())
            {
                for (unsigned i = 0; i < v.size(); i++)
                {
                    for (unsigned j = 0; j < v[i].size(); j++) {
                        ofs << v[i][j]; 
                        if (j < v[i].size() -1)
                            ofs << ", ";
                    }
                    if (i < v.size() -1)
                        ofs << std::endl;
                }
                ofs.close();
            }
            else
                return 1;
        }
        else
            std::cout << "Other formats are not possible yet." << std::endl;
        
        
        //std::cout << "Successfully wrote array with " << v.size() << " elements to " << std::string(name) << std::endl;
        return 0;
    }
    
    
    
private:
};


#endif /* WRITER_H */
