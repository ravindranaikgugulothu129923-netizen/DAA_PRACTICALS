#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph class
class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices);
    }

    // Add an edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line for directed graph
    }

    // DFS utility function
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbour : adjList[vertex]) {
            if (!visited[neighbour]) {
                DFSUtil(neighbour, visited);
            }
        }
    }

    // DFS Traversal
    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);

        cout << "DFS Traversal: ";
        DFSUtil(startVertex, visited);
        cout << endl;
    }

    // BFS Traversal
    void BFS(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            cout << vertex << " ";

            for (int neighbour : adjList[vertex]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph.addEdge(u, v);
    }

    int startVertex;

    cout << "Enter starting vertex: ";
    cin >> startVertex;

    cout << endl;

    // DFS
    graph.DFS(startVertex);

    // BFS
    graph.BFS(startVertex);

    return 0;
}
