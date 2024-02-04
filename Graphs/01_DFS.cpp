#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;
    vector<bool> visited;


public:
    Graph(int V) : vertices(V), adjacencyList(V), visited(V,false){
        
    }

    vector<vector<int>> getAdjacencyList(){
        return adjacencyList; 
    }

    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
    }

    void DFS(int startVertex) {

        cout<<startVertex<<" ";
        visited[startVertex] = true;

        for(auto& adj :adjacencyList[startVertex]){

            if(!visited[adj]){
                DFS(adj);
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

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
