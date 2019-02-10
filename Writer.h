#ifndef WRITER_H
#define WRITER_H

#include "Domain.h"
#include "Mesh.h"
#include <string>
#include <iostream>
#include <ostream>

class Writer
{
public:
    enum EFormat
    {
        CSV = 0,
        VTK = 1
    };
    
    Writer();
    
    int WriteSolution(const Mesh* const mesh, const double * const u, unsigned n, const char* name, EFormat format) const;
    int WriteNodes(std::vector<const Node*> coordinates, const char* name, EFormat format) const;    
    int WriteMesh(const Mesh* const mesh, const char* name, EFormat format) const;
    
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
        
        
        std::cout << "Successfully wrote array with " << v.size() << " elements to " << std::string(name) << std::endl;
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
        
        
        std::cout << "Successfully wrote array with " << v.size() << " elements to " << std::string(name) << std::endl;
        return 0;
    }
    
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            os << v[i];
        << ","
        }
    }
    
private:
};


#endif /* WRITER_H */
