#ifndef SHAPEFUNCTION_H
#define SHAPEFUNCTION_H

#include "Node.h"
#include <vector>
#include "Vector.h"
#include "Element.h"
#include "Matrix.h"

/*! \brief Abstract class representing the shape function.
*
 *  Attention: shape function is always on the unit element.
 */
class ShapeFunction
{
public:
    ShapeFunction() {}
    
    virtual ~ShapeFunction() {}
    
    //evaluate the shape function associated with point id at the value x
    virtual double Eval (int id, const Node& x) const = 0;
    //Get the derivative of the shape function associated with point id at the value x
    virtual Vector<double> DEval(int id, const Node& x) const = 0;

    //get the derivative matrix, where the columns are the different shape functions and the rows are the dimensions
    //i.e. a column is the DEval above
    virtual Matrix<double> DEval(const Node& x) const;

    virtual int GetNrShapeFunctions() const = 0;

    Matrix<double> GetJacobian(const Node& x, const Element* const elem) const;
    
protected:
    
};

#endif /* SHAPEFUNCTION_H */
