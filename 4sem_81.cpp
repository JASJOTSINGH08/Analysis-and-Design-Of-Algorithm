#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int>& nums, int target, int index, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (index == nums.size() || target < 0)
        return;

    current.push_back(nums[index]);
    subsetSum(nums, target - nums[index], index + 1, current, result);
    current.pop_back();
    subsetSum(nums, target, index + 1, current, result);
}

vector<vector<int>> findSubsets(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> current;
    subsetSum(nums, target, 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 7;
    
    vector<vector<int>> subsets = findSubsets(nums, target);
    
    cout << "Subsets with sum equal to " << target << " are:" << endl;
    for (const auto& subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
