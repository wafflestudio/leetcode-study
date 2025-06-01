#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size() * (nums.size() + 1) / 2;
        for (int& num: nums) {
            sum -= num;
        }
        return sum;
    }
};
