#include "Vertex.h"
#include "Edge.h"
Vertex::Vertex(char key)
{

	this->key = key;
	this->Next = nullptr; 
	this->Edges = nullptr;
}

void Vertex::addEdge(Vertex* adj, int weight)
{
	Edge* edge = new Edge(adj, weight);
	if (Edges == nullptr) {
		Edges = edge;
		Edges->Next = nullptr; // first edge will point to null
	}
	else {
		edge->Next = Edges; 
		Edges = edge; 
	}
}
