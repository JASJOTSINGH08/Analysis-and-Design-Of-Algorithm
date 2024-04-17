#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int assemblyLineScheduling(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x) {
    int n = a[0].size(); 

    vector<int> dp1(n); 
    vector<int> dp2(n); 

    dp1[0] = e[0] + a[0][0];
    dp2[0] = e[1] + a[1][0];

    for (int i = 1; i < n; ++i) {
        dp1[i] = min(dp1[i - 1] + a[0][i], dp2[i - 1] + t[1][i] + a[0][i]);
        dp2[i] = min(dp2[i - 1] + a[1][i], dp1[i - 1] + t[0][i] + a[1][i]);
    }

    return min(dp1[n - 1] + x[0], dp2[n - 1] + x[1]);
}

int main() {
    vector<vector<int>> a = {{4, 5, 3, 2}, {2, 10, 1, 4}}; 
    vector<vector<int>> t = {{0, 7, 4, 5}, {0, 9, 2, 8}};  
    vector<int> e = {10, 12};                              
    vector<int> x = {18, 7};                               

    cout << "Minimum time to exit: " << assemblyLineScheduling(a, t, e, x) << endl;

    return 0;
}
