#include <any>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // m[a] = b
        // b is index of (target - a)
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (m.contains(num)) {
                return {m[num], i};
            }
            m[target - num] = i;
        }

        // never reach
        return {0, 0};
    }
};
