// DFS algorithm in C++
// Header inclusions for input/output (cout) and linked lists (list)
#include <iostream>
#include <list>

// Using the `std` namespace to avoid repetitive `std::` prefixes
using namespace std;

// Define a `Graph` class to represent a graph data structure
class Graph {
public:
    // Constructor to initialize the graph with a specified number of ver
    Graph(int V) {
        numVertices = V; // Store the number of ver

        // Allocate memory for an array of linked lists to represent adjacency lists
        adjLists = new list<int>[numVertices]; 
        
        // Allocate memory for an array of booleans to track visited nodes during DFS
        visited = new bool[numVertices];

        // Initialize all nodes as unvisited (common practice for DFS)
        fill(visited, visited + numVertices, false);
    }

    // Add a directed edge from source vertex (`src`) to destination vertex (`dest`)
    void addEdge(int src, int dest) {
        adjLists[src].push_front(dest); // Add `dest` to the adjacency list of `src`
    }

    // Perform a Depth-First Search (DFS) traversal starting from a given vertex
    void DFS(int vertex) {
        visited[vertex] = true; // Mark the current vertex as visited

        // Get the adjacency list (list of neighbors) for the current vertex
        list<int> adjList = adjLists[vertex];

        // Print the current vertex to show the traversal order
        cout << vertex << " ";

        // Iterate through each neighbor (`*i`) in the adjacency list
        list<int>::iterator i;
        for (i = adjList.begin(); i != adjList.end(); ++i) {
            // If the neighbor hasn't been visited, recursively call DFS on it
            if (!visited[*i]) {
                DFS(*i);
            }
        }
    }

private:
    int numVertices;  // Number of ver in the graph
    list<int> *adjLists;  // Array of linked lists to store adjacency lists
    bool *visited;       // Array of booleans to track visited nodes during DFS
};

int main() {
    // Create a graph with 4 ver (nodes)
    Graph g(4);

    // Add edges to the graph (directed edges)
    g.addEdge(0, 1);  // Edge from vertex 0 to vertex 1
    g.addEdge(0, 2);  // Edge from vertex 0 to vertex 2
    g.addEdge(1, 2);  // Edge from vertex 1 to vertex 2
    g.addEdge(2, 3);  // Edge from vertex 2 to vertex 3

    // Perform DFS traversal starting from vertex 2 (can be any vertex)
    g.DFS(2);

    return 0; // Indicate successful program termination
}