#include <bits/stdc++.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> dp(N, 1);
        vector<int> pr(N, -1);
        for (int i = 0; i < N; i++) {
            int cur = nums[i];
            for (int j = 0; j < i; j++) {
                if (cur % nums[j] == 0) {
                    int new_sum = dp[j] + 1;
                    if (new_sum > dp[i]) {
                        dp[i] = new_sum;
                        pr[i] = j;
                    }
                }
            }
        }

        int max_sum = 0;
        int last = 0;
        for (int i = 0; i < N; i++) {
            if (dp[i] > max_sum) {
                max_sum = dp[i];
                last = i;
            }
        }

        vector<int> answer(max_sum);
        for (int i = max_sum - 1; i >= 0; i--) {
            answer[i] = nums[last];
            last = pr[last];
        }

        return answer;
    }
};


int main() {
    vector<int> nums {1,2,3};
    fmt::println("{}", Solution().largestDivisibleSubset(nums));
}
