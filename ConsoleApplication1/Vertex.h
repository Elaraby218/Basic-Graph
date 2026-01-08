#pragma once
class Edge;

// vertex contain more than one edge
// i wil implement them as a linked list 
// last edge is the start 

class Vertex
{
public :

	char key; 
	Vertex* Next; 
	Edge* Edges;  // will point to first edge we have


	Vertex(char key); 
	void addEdge(Vertex* adj, int weight);


};

