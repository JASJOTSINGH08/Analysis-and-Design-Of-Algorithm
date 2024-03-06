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


void spanning_tree(int E[], int graph[][100],int n) {
    cout << "Edges of Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; i++) {
        cout << E[i] << " - " << i << endl;
    }
}


void Prims(int graph[][100], int m , int n) {
    int E[100]; 
    int key[100]; 
    bool mstSet[100]; 

    for (int i = 0; i < n; i++) {
        key[i] = MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    E[0] = -1; 

    for (int k = 0; k < n - 1; k++) {
        int u = min_vertex(key, mstSet); 
        mstSet[u] = true; 

    
        for (int j = 0; j < m; j++) {
            if (graph[u][j] && !mstSet[j] && graph[u][j] < key[j]) {
                E[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    spanning_tree(E, graph,n);
}


int main(){
    int m,x;
    cout<<"Enter the no of edges : ";
    cin >> m; 
    cout<<"Enter no of vertices : ";
    cin >> x;

    int graph[100][100];
    cout << "Enter the edges and weights:" << endl;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c; 
    }

    Prims(graph, m, n);

    return 0;
}
