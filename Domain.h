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
    /*! \brief Constructor. Takes the mesh.
    * 
    */
    Domain(Mesh const * const  mesh);
    ~Domain();
    
    const Mesh * const GetMesh() const {return mesh_;}
    
    void SetIntegrator(const Integrator* i) {integrator = i;}
    void SetEquation(const Equation* e) {equation = e;}
    void SetShapeFunction(const ShapeFunction* s) {shapefunction = s;}
    void SetBoundaryCondition(const BoundaryCondition* bc) {boundarycondition = bc;}
    
    const Integrator* const GetIntegrator() const {return integrator;}
    const Equation* const GetEquation() const {return equation;}
    const ShapeFunction* const GetShapeFunction() const {return shapefunction;}
    const BoundaryCondition* const GetBoundaryCondition() const {return boundarycondition;}
    
private:
    const Mesh * const mesh_; 
    
    const Integrator* integrator;
    const Equation* equation;
    const ShapeFunction* shapefunction;
    const BoundaryCondition* boundarycondition;
};
    
#endif /*DOMAIN_H*/
