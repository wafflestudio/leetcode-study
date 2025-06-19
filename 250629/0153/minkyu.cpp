#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1 || nums[0] == -5000) return nums[0];
        int prev = -5001;
        for (int& n: nums) {
            if (n < prev) return n;
            prev = n;
        }
        return nums[0];
    }
};
