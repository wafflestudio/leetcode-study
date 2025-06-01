#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> map;
        set<int> s;
        for (int& num: nums) {
            map[num]++;
            s.insert(num);
        }
        vector<int> unique_nums;
        copy(s.begin(), s.end(), back_inserter(unique_nums));

        vector<vector<int>> answer;
        for (int i = 0; i < unique_nums.size(); i++) {
            int num = unique_nums[i];
            if (num > 0) break;
            map[num]--;
            for (int j = i; j < unique_nums.size(); j++) {
                int num2 = unique_nums[j];
                if (map[num2] == 0 || num2 > -(num / 2)) continue;
                map[num2]--;
                int remain = -(num + num2);
                if (map[remain] > 0) answer.push_back({num, num2, remain});
                map[num2]++;
            }
            map[num]++;
        }

        return answer;
    }
};
