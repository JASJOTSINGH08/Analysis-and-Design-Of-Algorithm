#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compareItemsByValue(const Item& a, const Item& b) {
    return a.value > b.value; // Sort items in descending order of value
}

double knapsack(int W, const vector<Item>& items) {
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareItemsByValue);

    double totalValue = 0.0;
    for (const auto& item : sortedItems) {
        if (W >= item.weight) {
            totalValue += item.value;
            W -= item.weight;
        } else {
            totalValue += (static_cast<double>(W) / item.weight) * item.value;
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {
        {1, 15},
        {2, 3},
        {2, 2},
        {3, 6},
        {3, 8}
    };

    int capacity = 10;
    double maxValue = knapsack(capacity, items);

    cout << "Maximum value obtained from knapsack: " << maxValue << endl;

    return 0;
}
