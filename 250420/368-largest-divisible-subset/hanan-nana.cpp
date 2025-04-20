#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> max_length;

    // DP[i] : i번째 원소의 가능 배열
    vector<int> DP[1000];

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int answer = 0, max_length = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
            DP[i].push_back(nums[i]);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && DP[j].size() + 1 > DP[i].size()) {
                    DP[i] = DP[j];
                    DP[i].push_back(nums[i]);
                }
            }
            if (DP[i].size() > max_length) {
                answer = i;
                max_length = DP[i].size();
            }
        }
        
        return DP[answer];
    }
};