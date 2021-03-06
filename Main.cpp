
#include "Domain.h"
#include "Meshgenerator.h"
#include "Solver.h"
#include "Writer.h"
#include "Integrator.h"
#include "ConstantIntegrator.h"
#include "EnergyFunction.h"
#include "LaplaceEnergyFunction.h"
#include "ShapeFunction.h"
#include "PolynomialShapeFunction.h"
#include "SourceFunction.h"
#include "TestSourceFunction.h"
#include "LapackSolver.h"
#include "EigenSolver.h"
#include "BoundaryCondition.h"
#include "DirichletBC.h"

#include <iostream>
#include <exception>
#include <cstdlib>

int main(int argc, char * argv [])
{
    try
    {
        Meshgenerator test_generator;
        int n = argc == 2 ? std::stoi(argv[1]) : 3;
        std::cout << "number of triangles in 1 direction = " << n << std::endl;
        const Mesh* const testmesh = test_generator.Generate(n);
        
        
        Integrator* integrator = new ConstantIntegrator();
        EnergyFunction* energyfct = new LaplaceEnergyFunction();
        SourceFunction* sourcefct = new TestSourceFunction();
        ShapeFunction* shapefct = new PolynomialShapeFunction(2, 1);  
        BoundaryCondition* bc = new DirichletBC();
        
        Domain*  testdomain = new Domain(testmesh);
        testdomain->SetIntegrator(integrator);
        testdomain->SetEquation(new Equation(energyfct, sourcefct));
        testdomain->SetShapeFunction(shapefct);
        testdomain->SetBoundaryCondition(bc);
               
        
        Writer writer;
        writer.WriteMesh(testdomain->GetMesh(), "Testdomain", "input", Writer::EFormat::CSV);
        
        Solver* testsolver = new EigenSolver();
        
        testsolver->Solve(testdomain);
        
        delete testdomain; 
        delete testmesh;
        delete testsolver;    
        
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "Ended program successfully." << std::endl;
    
    return 0;
}
