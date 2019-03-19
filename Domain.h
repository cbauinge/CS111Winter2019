#ifndef DOMAIN_H
#define DOMAIN_H


#include "Mesh.h"
#include "Integrator.h"
#include "Equation.h"
#include "ShapeFunction.h"
#include "BoundaryCondition.h"


/*! \brief Class representing the computational domain.
 *
 *  Class representing the computational domain. Connects equation, intgerator, shapefunctions and boundary condition with the geomtry.
 */
class Domain
{
public:
    /*! \brief Constructor. Takes the mesh and stores it in member.
    * 
    */
    Domain(Mesh const * const  mesh);
    /*! \brief Destructor. Deletes integrator, equation, shapefunction and boundarycondition.
    * 
    */
    ~Domain();
    
    /*! \brief Getter for the mesh.
    * 
    * \return The mesh.
    */
    const Mesh * const GetMesh() const {return mesh_;}
    
    /*! \brief Setter for the integrator.
    */
    void SetIntegrator(const Integrator* i) {integrator = i;}
    /*! \brief Setter for the equation.
    */
    void SetEquation(const Equation* e) {equation = e;}
    /*! \brief Setter for the function.
    */
    void SetShapeFunction(const ShapeFunction* s) {shapefunction = s;}
    /*! \brief Setter for the boundary condition.
    */
    void SetBoundaryCondition(const BoundaryCondition* bc) {boundarycondition = bc;}
    
    /*! \brief Getter for the integrator.
    */
    const Integrator* const GetIntegrator() const {return integrator;}
    /*! \brief Getter for the equation.
    */
    const Equation* const GetEquation() const {return equation;}
    /*! \brief Getter for the shape function.
    */
    const ShapeFunction* const GetShapeFunction() const {return shapefunction;}
    /*! \brief Getter for the boundary condition.
    */
    const BoundaryCondition* const GetBoundaryCondition() const {return boundarycondition;}
    
private:
    const Mesh * const mesh_; 
    
    const Integrator* integrator;
    const Equation* equation;
    const ShapeFunction* shapefunction;
    const BoundaryCondition* boundarycondition;
};
    
#endif /*DOMAIN_H*/
