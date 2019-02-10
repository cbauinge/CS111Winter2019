
#include "Domain.h"
#include "Meshgenerator.h"
#include "Solver.h"
#include "Writer.h"

int main(int argc, char * argv [])
{
    Meshgenerator test_generator;
    int n = argc == 2 ? std::stoi(argv[1]) : 1;
    std::cout << "n = " << n << std::endl;
    const Mesh* const testmesh = test_generator.Generate(n);
    
    Domain*  testdomain = new Domain(testmesh);
    Writer writer;
    writer.WriteMesh(testdomain->GetMesh(), "Testdomain", Writer::EFormat::CSV);
    
    Solver testsolver;
    
    testsolver.Solve(testdomain);
    
    delete testdomain; 
    delete testmesh;
    
    
    return 0;
}
