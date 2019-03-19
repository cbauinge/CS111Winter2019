#ifndef BOUNDARYCONDITION_H
#define BOUNDARYCONDITION_H


#include "Node.h"

/*! \brief Class representing the boundary condition.
 *
 *  Class representing the boundary condition. Stores information about the type (Neumann 
 *  oder Dirichlet) and lets the function be evaluated. How to use this i NOT part of this class.
 */
class BoundaryCondition
{
public:
    /*! \brief Enum indicating the type of the boundary condition
    *
    * Currently only supports Dirichlet and Neumand condition.
    */
    enum Type
    {
        Dirichlet = 0,
        Neumann = 1
    };

    /*! \brief Constructor. Takes the type and sets it
    *
    */
    BoundaryCondition(Type type);
    /*! \brief Constructor. Does nothing.
    *
    */
    virtual ~BoundaryCondition();

    /*! \brief Getter for the type.
    * 
    * \return The type member stored in this class.
    */
    Type GetType() const {return bc_type_;}

    /*! \brief Function that evaluates the boundary condition at the given point..
    * 
    * @param[in] The point where we want to get the boundary value.
    * \return The value of the bc on the given point.
    */
    virtual double Eval(const Node& x) const = 0;

protected:
    Type bc_type_;


};


#endif /* BOUNDARYCONDITION_H */