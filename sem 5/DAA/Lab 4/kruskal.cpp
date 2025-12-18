#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    char src, dest;
    int weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
    char parent[256]; 
public:
    DSU() {
        for (int i = 0; i < 256; i++) {
            parent[i] = i; 
        }
    }

    char find(char v) {
        while (parent[v] != v) {
            v = parent[v];
        }
        return v;
    }

    bool unionSets(char a, char b) {
        char rootA = find(a);
        char rootB = find(b);
        if (rootA == rootB)
            return false; 

        parent[rootA] = rootB; 
        return true;
    }
};

void kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> result;
    DSU dsu;
    
    sort(edges.begin(), edges.end(), compareEdges);

    int mstWeight = 0;

    for (int i = 0; i < edges.size(); i++) {
        Edge edge = edges[i];

        if (dsu.unionSets(edge.src, edge.dest)) {
            result.push_back(edge);
            mstWeight += edge.weight;
            if (result.size() == V - 1) break; 
        }
    }

    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << "\n";
    }
    cout << "Total Weight of MST: " << mstWeight << endl;
}

int main() {
    int E;
    cout << "Enter number of edges: ";
    cin >> E;
    
    vector<Edge> edges;
    vector<char> nodes;

    cout << "Enter edges (src dest weight) :\n";
    for (int i = 0; i < E; i++) {
        Edge edge;
        cin >> edge.src >> edge.dest >> edge.weight;
        edges.push_back(edge);
        
        if (find(nodes.begin(), nodes.end(), edge.src) == nodes.end()) 
            nodes.push_back(edge.src);
        if (find(nodes.begin(), nodes.end(), edge.dest) == nodes.end()) 
            nodes.push_back(edge.dest);
    }

    int V = nodes.size();

    kruskalMST(edges, V);
    return 0;
}  
