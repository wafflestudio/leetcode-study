#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void collect(vector<int>& candidates, int target, int prev_index, vector<int>& cum, vector<vector<int>>& answer) {
        if (target < 0) return;
        if (target == 0) {
            answer.push_back(vector<int>(cum));
        }

        for (int i = prev_index; i < candidates.size(); ++i) {
            int candi = candidates[i];
            cum.push_back(candi);
            collect(candidates, target - candi, i, cum, answer);
            cum.pop_back();
        }
    } 

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> cum;
        collect(candidates, target, 0, cum, answer);
        return answer;
    }
};
