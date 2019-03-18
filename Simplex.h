#ifndef SIMPLEX_H
#define SIMPLEX_H

#include<vector>
#include <ostream>
#include "Element.h"
#include "Node.h"
#include "Edge.h"


/*! \brief Simplicial element. Specific kind of element for the mesh.
 *
 *  Derived from Element.
 */
class Simplex : public Element
{
public:
    Simplex(std::vector<Node*>& nodes, std::vector<Edge*>& edges, double area);
    
    
    virtual double GetArea() const {return area_;}
    
protected:
    virtual bool IsNondegenerate() const;
    virtual std::ostream& Dump(std::ostream& os) const;
    
private:
    double area_;
    
};




#endif /* SIMPLEX_H */
