#ifndef DOMAIN_H
#define DOMAIN_H


#include "Mesh.h"

class Domain
{
public:
    Domain(Mesh const * const  mesh);
    
    const Mesh * const GetMesh() const {return mesh_;}
    
private:
    const Mesh * const mesh_; 
};
    
#endif /*DOMAIN_H*/
