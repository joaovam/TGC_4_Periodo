#makefile
all:  Vertex Edge Node AdjacencyList AdjacencyMatrix main exec

AdjacencyList:
	@echo "AdjacencyList Building"
	g++ -c AdjacencyList.cpp

AdjacencyMatrix:
	@echo "AdjacencyMatrix Building"
	g++ -c AdjacencyMatrix.cpp
Node:
	@echo "Node Building"
	g++ -c Node.cpp
Vertex:
	@echo "Vertex Building"
	g++ -c Vertex.cpp
Edge:
	@echo "Edge Building"
	g++ -c Edge.cpp

main:
	@echo "main Building"
	g++ -c main.cpp
exec:
	@echo "Creating Exec"
	g++ *.o
debug:
	@echo "Creating Debug"
	g++ -g *.o

clean:
	del /s *.o *.d *.exe *.out