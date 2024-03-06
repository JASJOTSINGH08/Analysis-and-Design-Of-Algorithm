#include<iostream>
#include<vector>
#include<climits>

using namespace std;

const int n = 5;
const int MAX = INT_MAX;

int min_vertex(int near[], bool cost[]) {
    int key = MAX, minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!cost[i] && near[i] < key) {
            key = near[i];
            minIndex = i;
        }
    }
    return minIndex;
}


void spanning_tree(int E[], int graph[n][n]) {
    cout << "Edges of Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; i++) {
        cout << E[i] << " - " << i << endl;
    }
}


void Prims(int graph[n][n]) {
    int E[n]; 
    int key[n]; 
    bool mstSet[n]; 

    for (int i = 0; i < n; i++) {
        key[i] = MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    E[0] = -1; 

    for (int k = 0; k < n - 1; k++) {
        int u = min_vertex(key, mstSet); 
        mstSet[u] = true; 

    
        for (int j = 0; j < n; j++) {
            if (graph[u][j] && !mstSet[j] && graph[u][j] < key[j]) {
                E[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    spanning_tree(E, graph);
}


int main(){
     int graph[n][n] = {
        0, 6, 4, 7,
        6, 0, 1, 0,
        4, 1, 0, 5,
        7, 0, 5, 0
    };

    Prims(graph);

    return 0;
}
