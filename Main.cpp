
#include "Domain.h"
#include "Meshgenerator.h"
#include "Solver.h"

int main(int argc, char * argv [])
{
    Meshgenerator test_generator;
    const Mesh* const testmesh = test_generator.Generate(1);
    
    Domain*  testdomain = new Domain(testmesh);
    
    Solver testsolver;
    
    testsolver.Solve(testdomain);
    
    delete testdomain; 
    delete testmesh;
    
    
    return 0;
}
