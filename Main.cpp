
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

#include <iostream>
#include <exception>

int main(int argc, char * argv [])
{
    try
    {
        Meshgenerator test_generator;
        int n = argc == 2 ? std::stoi(argv[1]) : 3;
        std::cout << "number of triangles in 1 direction = " << n << std::endl;
        const Mesh* const testmesh = test_generator.Generate(n);
        
        
        Integrator* integrator = new ConstantIntegrator(testmesh);
        EnergyFunction* energyfct = new LaplaceEnergyFunction();
        ShapeFunction* shapefct = new PolynomialShapeFunction(2, 1);       
        
        
        Domain*  testdomain = new Domain(testmesh);
        testdomain->SetIntegrator(integrator);
        testdomain->SetEnergyFunction(energyfct);
        testdomain->SetShapeFunction(shapefct);
               
        
        Writer writer;
        writer.WriteMesh(testdomain->GetMesh(), "Testdomain", "input", Writer::EFormat::CSV);
        
        Solver testsolver;
        
        testsolver.Solve(testdomain);
        
        delete testdomain; 
        delete testmesh;    
        
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    

}
