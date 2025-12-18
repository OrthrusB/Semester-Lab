#include <iostream>
#include <climits>

using namespace std;

int V;

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

void printMST(int parent[], int** graph, char vertices[]) {
    cout << "\nMinimum Spanning Tree (MST):\n";
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << vertices[parent[i]] << " - " << vertices[i] << "\t" << graph[i][parent[i]] << "\n";
}

void primMST(int** graph, char vertices[]) {
    int* parent = new int[V]; 
    int* key = new int[V];  
    bool* mstSet = new bool[V]; 

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;     
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true; 
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, vertices);

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> V;

    char* vertices = new char[V]; 
    int** graph = new int*[V];

    for (int i = 0; i < V; i++)
        graph[i] = new int[V];

    cout << "Enter " << V << " vertex names (single characters): ";
    for (int i = 0; i < V; i++)
        cin >> vertices[i];

    cout << "\nEnter adjacency matrix (enter 0 for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, vertices);

    for (int i = 0; i < V; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] vertices;

    return 0;
}

