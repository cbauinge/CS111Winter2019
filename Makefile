CXX=g++
CXXFLAGS = -Wall -g


main: Main.o Domain.o Meshgenerator.o Solver.o Mesh.o
	$(CXX) $(CXXFLAGS) -o main Main.o Domain.o Solver.o Mesh.o Meshgenerator.o
	
	
Main.o: Main.cpp Domain.o Solver.o Meshgenerator.o Mesh.o
	$(CXX) $(CXXFLAGS) -c Main.cpp
	
Solver.o: Solver.cpp Solver.h Domain.h
	$(CXX) $(CXXFLAGS) -c Solver.cpp
	
Domain.o: Domain.cpp Domain.h Mesh.h
	$(CXX) $(CXXFLAGS) -c Domain.cpp
	
Meshgenerator.o: Meshgenerator.cpp Meshgenerator.h Mesh.h
	$(CXX) $(CXXFLAGS) -c Meshgenerator.cpp
	
Mesh.o: Mesh.cpp Mesh.h Simplex.h Node.h Edge.h
	$(CXX) $(CXXFLAGS) -c Mesh.cpp
	

	
clean:
	rm -f *.o main
