#include "Edge.h"
#include "Vertex.h"


Edge::Edge(Vertex* adj, int weight)
{
	this->Adj = adj;
	this->weight = weight;
	this->Next = nullptr; 
}
