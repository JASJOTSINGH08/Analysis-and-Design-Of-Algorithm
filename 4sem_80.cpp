#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int vertex, int color, const vector<vector<int>>& graph, const vector<int>& colorAssignment) {
    for (int neighbor : graph[vertex]) {
        if (colorAssignment[neighbor] == color) {
            return false; 
        }
    }
    return true;
}

bool colorVertices(int vertex, int numColors, const vector<vector<int>>& graph, vector<int>& colorAssignment) {
    if (vertex == graph.size()) {
        return true;
    }

    for (int color = 1; color <= numColors; color++) {
        if (isSafe(vertex, color, graph, colorAssignment)) {
            colorAssignment[vertex] = color; 

            if (colorVertices(vertex + 1, numColors, graph, colorAssignment)) {
                return true; 
            }

            colorAssignment[vertex] = 0;
        }
    }

    return false; 
}

bool solveNColoring(int numVertices, int numColors, const vector<vector<int>>& graph) {
    vector<int> colorAssignment(numVertices, 0); 

    if (!colorVertices(0, numColors, graph, colorAssignment)) {
        cout << "No solution exists!" << endl;
        return false;
    }

    cout << "Vertex colors: ";
    for (int color : colorAssignment) {
        cout << color << " ";
    }
    cout << endl;

    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},     
        {0, 2, 3},  
        {0, 1, 3},  
        {1, 2}      
    };

    int numVertices = graph.size();
    int numColors = 3; 

    solveNColoring(numVertices, numColors, graph);

    return 0;
}
