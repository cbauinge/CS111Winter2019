LIBS = -L/usr/x86_64-linux-gnu/ -llapacke
PATHS = -I /usr/include/ -I /home/cbauinge/Documents/eigen/

CXX = g++
CXXFLAGS = -Wall -g -fopenmp
#CXX = pgc++
#CXXFLAGS=-fast -Minfo=all,intensity,ccff -mp -std=c++11



main: Main.o Domain.o Meshgenerator.o Solver.o Mesh.o Writer.o Node.o Edge.o Simplex.o Polynomial.o Multiindex.o LaplaceEnergyFunction.o \
PolynomialShapeFunction.o Integrator.o ConstantIntegrator.o Element.o TestSourceFunction.o SourceFunction.o Equation.o LapackSolver.o \
ShapeFunction.o BoundaryCondition.o DirichletBC.o EigenSolver.o
	$(CXX) $(CXXFLAGS) -o main Main.o Domain.o Solver.o Mesh.o Meshgenerator.o Writer.o Node.o Edge.o Simplex.o Polynomial.o \
	Multiindex.o LaplaceEnergyFunction.o PolynomialShapeFunction.o Integrator.o ConstantIntegrator.o Element.o TestSourceFunction.o \
	SourceFunction.o Equation.o LapackSolver.o ShapeFunction.o BoundaryCondition.o DirichletBC.o EigenSolver.o $(LIBS) $(PATHS)
	
Main.o: Main.cpp Domain.o Solver.o Meshgenerator.o Mesh.o Writer.o Node.o Edge.o Simplex.o Polynomial.o Multiindex.o LaplaceEnergyFunction.o \
PolynomialShapeFunction.o Integrator.o ConstantIntegrator.o Element.o TestSourceFunction.o SourceFunction.o Equation.o LapackSolver.o \
ShapeFunction.o BoundaryCondition.o DirichletBC.o EigenSolver.o
	$(CXX) $(CXXFLAGS) -c Main.cpp $(LIBS) $(PATHS)
	
Solver.o: Solver.cpp Solver.h
	$(CXX) $(CXXFLAGS) -c Solver.cpp $(LIBS) $(PATHS)

LapackSolver.o: LapackSolver.cpp LapackSolver.h
	$(CXX) $(CXXFLAGS) -c LapackSolver.cpp $(LIBS) $(PATHS)

EigenSolver.o: EigenSolver.cpp EigenSolver.h
	$(CXX) $(CXXFLAGS) -c EigenSolver.cpp $(PATHS)
	
Domain.o: Domain.cpp Domain.h Mesh.h
	$(CXX) $(CXXFLAGS) -c Domain.cpp
	
Meshgenerator.o: Meshgenerator.cpp Meshgenerator.h Mesh.h
	$(CXX) $(CXXFLAGS) -c Meshgenerator.cpp
	
Writer.o: Writer.cpp Writer.h Node.h
	$(CXX) $(CXXFLAGS) -c Writer.cpp
	
Mesh.o: Mesh.cpp Mesh.h Node.o Simplex.o Edge.o Simplex.h Node.h Edge.h
	$(CXX) $(CXXFLAGS) -c Mesh.cpp
	
Node.o: Node.h Node.cpp
	$(CXX) $(CXXFLAGS) -c Node.cpp
	
Edge.o: Edge.h Edge.cpp
	$(CXX) $(CXXFLAGS) -c Edge.cpp
	
Element.o: Element.h Element.cpp
	$(CXX) $(CXXFLAGS) -c Element.cpp

Simplex.o: Simplex.h Simplex.cpp
	$(CXX) $(CXXFLAGS) -c Simplex.cpp
	
Polynomial.o: Polynomial.h Polynomial.cpp
	$(CXX) $(CXXFLAGS) -c Polynomial.cpp

Multiindex.o: Multiindex.h Multiindex.cpp
	$(CXX) $(CXXFLAGS) -c Multiindex.cpp

LaplaceEnergyFunction.o: LaplaceEnergyFunction.h LaplaceEnergyFunction.cpp
	$(CXX) $(CXXFLAGS) -c LaplaceEnergyFunction.cpp

PolynomialShapeFunction.o: PolynomialShapeFunction.h PolynomialShapeFunction.cpp
	$(CXX) $(CXXFLAGS) -c PolynomialShapeFunction.cpp
	
Integrator.o: Integrator.h Integrator.cpp
	$(CXX) $(CXXFLAGS) -c Integrator.cpp
	
ConstantIntegrator.o: ConstantIntegrator.h ConstantIntegrator.cpp
	$(CXX) $(CXXFLAGS) -c ConstantIntegrator.cpp

Equation.o: Equation.h Equation.cpp
	$(CXX) $(CXXFLAGS) -c Equation.cpp

SourceFunction.o: SourceFunction.h SourceFunction.cpp
	$(CXX) $(CXXFLAGS) -c SourceFunction.cpp

ShapeFunction.o: ShapeFunction.h ShapeFunction.cpp
	$(CXX) $(CXXFLAGS) -c ShapeFunction.cpp

TestSourceFunction.o: TestSourceFunction.h TestSourceFunction.cpp
	$(CXX) $(CXXFLAGS) -c TestSourceFunction.cpp

BoundaryCondition.o: BoundaryCondition.h BoundaryCondition.cpp
	$(CXX) $(CXXFLAGS) -c BoundaryCondition.cpp

DirichletBC.o: DirichletBC.h DirichletBC.cpp
	$(CXX) $(CXXFLAGS) -c DirichletBC.cpp

	
clean:
	rm -f *.o main


