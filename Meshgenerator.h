#ifndef MESHGENERATOR_H
#define MESHGENERATOR_H

#include "Mesh.h"


class Meshgenerator
{
public:
    Meshgenerator();
    
    //Generates a simplex mesh in the unit sqare where n indicates the number of elements on one boundary
    const Mesh* const Generate(int n) const;
    
private:
    int GetEdgeIdFromNodes(const Node* node1, const Node* node2, std::vector<Edge*>& edges) const;
    
    
};

#endif /* MESHGENERATOR_H */
