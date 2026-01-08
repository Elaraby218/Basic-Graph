#include<iostream>
using namespace std; 
#include "Graph.h"

int main() {
	Graph g; 
	g.addVertex('a');
	g.addVertex('b');
	g.addVertex('c');
	g.addVertex('d');
	g.addVertex('e');

	g.addEdge('a', 'b', 15);
	g.addEdge('b', 'd', 15);
	g.addEdge('b', 'e', 15);
	g.addEdge('e', 'd', 15);
	g.addEdge('d', 'c', 15);
	

	g.printGraphWithEdges();
	cout << endl; 

	cout << "DFS ... " << endl; 
	g.DFS('a', 'c');
	

	cout << endl << endl; 

	cout << "BFS ... " << endl;
	g.BFS('a', 'c');

}