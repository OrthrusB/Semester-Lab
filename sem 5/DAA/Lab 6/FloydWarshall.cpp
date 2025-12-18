#include <iostream>
#include <climits>

using namespace std;
void floydWarshall(int **graph, int V);

int main()
{
    int V;

    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    // Input validation
    if (cin.fail() || V <= 0) {
        cout << "Invalid input for number of vertices" << endl;
        return 1;
    }

    // Create a 2D array to represent the graph
    int **graph = new int *[V];
    for (int i = 0; i < V; ++i)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; ++j)
        {
            cout << "Enter the weight from vertex " << i << " to vertex " << j 
                 << " (or " << INT_MAX << " if no direct edge): ";
            cin >> graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm
    floydWarshall(graph, V);

    // Cleanup memory
    for (int i = 0; i < V; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}

void floydWarshall(int **graph, int V)
{
    // Create distance array
    int **dist = new int *[V];
    for (int i = 0; i < V; ++i)
    {
        dist[i] = new int[V];
        for (int j = 0; j < V; ++j)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Graph contains negative cycle" << endl;
            // Cleanup memory before returning
            for (int j = 0; j < V; j++) {
                delete[] dist[j];
            }
            delete[] dist;
            return;
        }
    }

    // Print results
    cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "INF\t";
            }
            else
            {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }

    
    for (int i = 0; i < V; i++) {
        delete[] dist[i];
    }
    delete[] dist;
}
