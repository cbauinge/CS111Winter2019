CXX=g++
CXXFLAGS = -Wall -g
LIBS = -L/usr/x86_64-linux-gnu/ -llapacke
PATHS = -I /usr/include/



main: Main.o Domain.o Meshgenerator.o Solver.o Mesh.o Writer.o Node.o Edge.o Simplex.o
	$(CXX) $(CXXFLAGS) -o main Main.o Domain.o Solver.o Mesh.o Meshgenerator.o Writer.o Node.o Edge.o Simplex.o $(LIBS)
	
	
Main.o: Main.cpp Domain.o Solver.o Meshgenerator.o Mesh.o Writer.o Node.o Edge.o Simplex.o
	$(CXX) $(CXXFLAGS) -c Main.cpp $(LIBS)
	
Solver.o: Solver.cpp Solver.h Domain.h Writer.h
	$(CXX) $(CXXFLAGS) -c Solver.cpp $(PATHS) $(LIBS)
	
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
	
Simplex.o: Simplex.h Simplex.cpp
	$(CXX) $(CXXFLAGS) -c Simplex.cpp

	
clean:
	rm -f *.o main
