#ifndef SHAPEFUNCTION_H
#define SHAPEFUNCTION_H

#include "Node.h"

class ShapeFunction
{
public:
    ShapeFunction() {}
    
    virtual ~ShapeFunction() {}
    
    virtual double operator() (const Node& x) const = 0;
    
private:
    
};

#endif /* SHAPEFUNCTION_H */
