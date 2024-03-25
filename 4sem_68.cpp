#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

static bool cmp(pair<double, Item> a, pair<double, Item> b) {
    return a.first > b.first;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    vector<pair<double, Item>> v;

    for (int i = 0; i < n; ++i) {
        double perUnitValue = static_cast<double>(arr[i].value) / arr[i].weight;
        pair<double, Item> p = make_pair(perUnitValue, arr[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    double totalValue = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].second.weight > W) {
            totalValue += W * v[i].first;
            W = 0;
        } else {
            totalValue += v[i].second.value;
            W -= v[i].second.weight;
        }
    }
    return totalValue;
}

int main() {
    Item arr[5] = {
        {1, 15},
        {2, 3},
        {2, 2},
        {3, 6},
        {3, 8}
    };

    double val = fractionalKnapsack(50, arr, 5);
    cout << "Maximum value obtained from fractional knapsack: " << val << endl;

    return 0;
}
