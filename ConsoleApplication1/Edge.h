#pragma once
class Vertex;

class Edge
{
public:
	int weight; 
	Vertex* Adj;

	Edge* Next; 

	Edge(Vertex* adj, int weight);
	
	

};

