#include <iostream>
#include <climits>
using namespace std;

struct Graph{
    int path[4];
    int length;
};

Graph fcost (int cost [4][4], int n_v , int k){
int fcost[n_v];
fcost[n_v - 1] = 0;
int d[n_v];
int path[k];
int r;

for ( int j = n_v -2; j>=0 ; j--){

    int minDistance = INT16_MAX;

    for (int i = j + 1; i < n_v; i++) {
        if (cost[j][i] != 0 && cost[j][i] != INT16_MAX) {
            if (cost[j][i] + fcost[i] < minDistance) {
                r = i;
                minDistance = cost[j][i] + fcost[i];
            }
        }
    }
        fcost[j]= cost[j][r]+ fcost[r];
        d[j] = r;
    }
Graph graph;
graph.length = fcost[0];
graph.path[0] = 1;
graph.path[k - 1]= n_v;

for ( int a = 1 ; a < k -1 ; a++){
    graph.path[a]= d[graph.path[a - 1]-1] + 1;
}
return graph;
}

int main(){

int cost [4][4] = {
    {0,1,2,3},
    {INT16_MAX,0,1,2},
    {INT16_MAX,0,INT16_MAX,1},
    {INT16_MAX,INT16_MAX,0,1}};

int n_v = 4;
int p_v = 4;

    Graph graph = fcost(cost, n_v, p_v);

    cout << "Minimum cost path length : " << graph.length << endl;

    cout << "Path: ";
    for (int i = 0; i < p_v; i++) {
        cout << graph.path[i] << " ";
    }
}



