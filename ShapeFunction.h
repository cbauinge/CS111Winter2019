#ifndef SHAPEFUNCTION_H
#define SHAPEFUNCTION_H

#include "Node.h"
#include <vector>

//Abstract class that represents the shape funcitons on the unit element
class ShapeFunction
{
public:
    ShapeFunction() {}
    
    virtual ~ShapeFunction() {}
    
    //evaluate the shape function associated with point id at the value x
    virtual double Eval (int id, const Node& x) const = 0;
    //Get the derivative of the shape function associated with point id at the value x
    virtual std::vector<double> DEval(int id, const Node& x) const = 0;
    
private:
    
};

#endif /* SHAPEFUNCTION_H */
