#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    vector<vector<int>> getAdjacencyList(){
        return adjacencyList; 
    }

    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
    }

    void BFS(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    q.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    Graph g(6);

   vector<vector<int>> adjList = g.getAdjacencyList();

    // Printing the adjacency list
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Adjacency List for vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
