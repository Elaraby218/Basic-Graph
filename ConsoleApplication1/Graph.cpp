#include "Graph.h"
#include "Edge.h"
#include<map>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

// constructor, i will make it start with empty 
Graph::Graph() {
	start = nullptr; 
}

void Graph::addVertex(char key)
{
	Vertex* newVertext = new Vertex(key);
	if (start == nullptr) {
		start = newVertext;
		start->Next = nullptr;
	}
	else {
		newVertext->Next = start; 
		start = newVertext;
	}
}

void Graph::printGraph()
{
	Vertex* cur = this->start; 
	while (cur != nullptr) {
		cout << cur->key << endl;
		cur = cur->Next; 
	}
}

void Graph::printGraphWithEdges() {
	Vertex* cur = this->start;

	while (cur != nullptr) {
		cout << "Vertex " << cur->key << " edges:" << endl;

		Edge* curEdge = cur->Edges;
		while (curEdge != nullptr) {
			cout << " -> "
				<< curEdge->Adj->key
				<< " (weight " << curEdge->weight << ")"
				<< endl;

			curEdge = curEdge->Next;
		}

		cur = cur->Next;
	}
}


// i will assume that the user is a good one and will insert 
// existed srcKey and existed dstKey
void Graph::addEdge(char srcKey, char dstKey , int weight)
{
	Vertex* src = getVertexByKey(srcKey); 
	Vertex* dst = getVertexByKey(dstKey); 

	src->addEdge(dst, weight);
	dst->addEdge(src, weight); 
}


Vertex* Graph::getVertexByKey(char key)
{
	Vertex* cur = this->start;
	while (cur != nullptr) {
		if (cur->key == key) {
			return cur;
		}
		cur = cur->Next;
	}
	return nullptr;
}



// get the srcKey node 
// start itearate on its adjs
// we need visAttribute --> i will use map instead of make vis inside the vertix itself
// if(found) print the path -- for this implementation i will assume that all target always 
// have edge with the src (direct or indirect)
map<Vertex*, bool> vis;

void Graph::DFS(char srcKey, char targetKey)
{
	vis.clear();
	Vertex* srcNode = getVertexByKey(srcKey);
	if (!srcNode) return;

	searchDFS(srcNode, targetKey);
}

bool Graph::searchDFS(Vertex* cur, char targetKey)
{
	if (!cur) return false;
	if (vis[cur]) return false;

	vis[cur] = true;

	if (cur->key == targetKey) {
		cout << cur->key << " <- ";
		return true;
	}

	Edge* curEdge = cur->Edges;
	while (curEdge != nullptr) {
		if (searchDFS(curEdge->Adj, targetKey)) {
			cout << cur->key << " <- ";
			return true;   
			// here once i found node i should stop the whole while , do not cmoplete 
			// the dfs we reached our goal
		}

		curEdge = curEdge->Next;
	}

	return false;
}

void Graph::BFS(char srcKey, char targetKey)
{
	vis.clear();

	Vertex* srcNode = getVertexByKey(srcKey);
	if (!srcNode) return;

	queue<Vertex*> q;

	map<Vertex*, Vertex*> parent;

	q.push(srcNode);
	vis[srcNode] = true;
	parent[srcNode] = nullptr;

	while (!q.empty()) {

		Vertex* cur = q.front();
		q.pop();

	
		if (cur->key == targetKey) {
			// first i should build the path
			vector<Vertex*> path;
			Vertex* node = cur;

			while (node != nullptr) {
				path.push_back(node);
				node = parent[node];
			}

			
			for (int i = 0; i < path.size(); i++) {
				cout << path[i]->key;
				if (i < path.size() - 1) cout << " <- ";
			}
			cout << endl;
			return;
		}

		// visit adjs
		Edge* curEdge = cur->Edges;
		while (curEdge != nullptr) {
			if (!vis[curEdge->Adj]) {
				vis[curEdge->Adj] = true;
				parent[curEdge->Adj] = cur;
				q.push(curEdge->Adj);
			}
			curEdge = curEdge->Next;
		}
	}
}