# Graph Data Structure Implementation

A C++ implementation of an undirected weighted graph using adjacency lists with linked list representation.

## Project Structure

This project implements a graph data structure with three main classes:
- **Graph**: The main graph container
- **Vertex**: Represents a node in the graph
- **Edge**: Represents a weighted connection between vertices

## Class Overview

### 1. Edge Class (`Edge.h`, `Edge.cpp`)

Represents a weighted edge connecting to an adjacent vertex.

#### Data Members
- `int weight`: The weight/cost of the edge
- `Vertex* Adj`: Pointer to the adjacent vertex this edge connects to
- `Edge* Next`: Pointer to the next edge in the linked list

#### Functions
- **`Edge(Vertex* adj, int weight)`**: Constructor that initializes an edge with an adjacent vertex and weight

#### Structure
Edges are stored as a linked list, where each vertex maintains a list of its outgoing edges.

---

### 2. Vertex Class (`Vertex.h`, `Vertex.cpp`)

Represents a node/vertex in the graph.

#### Data Members
- `char key`: The unique identifier for the vertex
- `Vertex* Next`: Pointer to the next vertex in the graph's vertex list
- `Edge* Edges`: Pointer to the first edge in this vertex's edge list

#### Functions
- **`Vertex(char key)`**: Constructor that initializes a vertex with a key and sets pointers to nullptr
- **`void addEdge(Vertex* adj, int weight)`**: Adds a new edge to this vertex's edge list
  - Creates a new edge connecting to the adjacent vertex with the specified weight
  - Adds the edge at the beginning of the edge list (O(1) insertion)

#### Structure
Vertices are stored in a linked list within the Graph, and each vertex maintains its own linked list of edges.

---

### 3. Graph Class (`Graph.h`, `Graph.cpp`)

The main graph container that manages vertices and edges.

#### Data Members
- `Vertex* start`: Pointer to the first vertex in the graph's vertex list

#### Public Functions

##### **`Graph()`**
Constructor that initializes an empty graph with start pointer set to nullptr.

##### **`void addVertex(char key)`**
Adds a new vertex to the graph.
- Creates a new vertex with the given key
- Inserts it at the beginning of the vertex list (O(1) insertion)

##### **`void addEdge(char srcKey, char dstKey, int weight)`**
Adds an undirected weighted edge between two vertices.
- Finds both source and destination vertices by their keys
- Adds edge from source to destination
- Adds edge from destination to source (creates undirected connection)
- Assumes both vertices exist in the graph

##### **`void printGraph()`**
Prints all vertices in the graph.
- Iterates through the vertex linked list
- Displays each vertex's key

##### **`void printGraphWithEdges()`**
Prints the complete graph structure with all edges.
- For each vertex, displays:
  - The vertex key
  - All adjacent vertices with their edge weights
- Useful for visualizing the graph structure

##### **`void DFS(char srcKey, char targetKey)`**
Performs Depth-First Search to find a path from source to target vertex.
- Clears the visited map
- Finds the source vertex
- Calls the recursive `searchDFS` helper function
- Prints the path from target back to source when found

##### **`void BFS(char srcKey, char targetKey)`**
Performs Breadth-First Search to find the shortest path from source to target vertex.
- Uses a queue for level-order traversal
- Maintains a parent map to reconstruct the path
- Prints the shortest path from target to source
- Guarantees the shortest path (minimum number of edges)

#### Private Functions

##### **`Vertex* getVertexByKey(char key)`**
Helper function to find a vertex by its key.
- Iterates through the vertex list
- Returns pointer to the vertex if found, nullptr otherwise

##### **`bool searchDFS(Vertex* cur, char targetKey)`**
Recursive helper function for DFS.
- Marks current vertex as visited
- Returns true when target is found
- Recursively explores adjacent unvisited vertices
- Prints the path while backtracking

#### Implementation Details
- **Graph Representation**: Adjacency list using linked lists
- **Visited Tracking**: Global map (`map<Vertex*, bool> vis`) used for DFS/BFS
- **Edge Type**: Undirected (edges added in both directions)
- **Weighted**: Each edge has an integer weight

---

## Usage Example

```cpp
#include "Graph.h"

int main() {
    Graph g;
    
    // Add vertices
    g.addVertex('a');
    g.addVertex('b');
    g.addVertex('c');
    g.addVertex('d');
    g.addVertex('e');
    
    // Add edges (undirected, weighted)
    g.addEdge('a', 'b', 15);
    g.addEdge('b', 'd', 15);
    g.addEdge('b', 'e', 15);
    g.addEdge('e', 'd', 15);
    g.addEdge('d', 'c', 15);
    
    // Print graph structure
    g.printGraphWithEdges();
    
    // Find path using DFS
    cout << "DFS ... " << endl;
    g.DFS('a', 'c');
    
    // Find shortest path using BFS
    cout << "BFS ... " << endl;
    g.BFS('a', 'c');
    
    return 0;
}
```

## Features

- ? Dynamic vertex addition
- ? Undirected weighted edges
- ? Depth-First Search (DFS) with path printing
- ? Breadth-First Search (BFS) with shortest path
- ? Graph visualization with edges
- ? Memory-efficient linked list implementation

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| Add Vertex | O(1) |
| Add Edge | O(V) - needs to find vertices |
| DFS | O(V + E) |
| BFS | O(V + E) |
| Print Graph | O(V) or O(V + E) |

Where V = number of vertices, E = number of edges

## Data Structure Design

```
Graph
  ??> Vertex (linked list)
       ??> key: 'a'
       ??> Next -> Vertex ('b')
       ??> Edges -> Edge (linked list)
                     ??> Adj -> Vertex ('b')
                     ??> weight: 15
                     ??> Next -> Edge
```

## Notes

- The graph assumes vertices have unique character keys
- All edges are undirected (bidirectional)
- The implementation uses raw pointers (consider smart pointers for production code)
- The visited map is global for simplicity (could be refactored as a member variable)
