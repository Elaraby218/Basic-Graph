#pragma once
#include "Vertex.h"
#include "Vertex.h"
class Graph
{
public:
	
	Vertex* start;
	Graph(); 

	void addVertex(char key);
	void addEdge(char srckey, char dstKey, int weight);

	void printGraph(); // this only print the memory representatino
	void printGraphWithEdges();

	// DFS to fint node through another node
	// and will print the path

	void DFS(char srcKey, char targetKey);
	void BFS(char srcKey, char targetKey);


private:
	Vertex* getVertexByKey(char key);
	bool searchDFS(Vertex* src, char target);
};

