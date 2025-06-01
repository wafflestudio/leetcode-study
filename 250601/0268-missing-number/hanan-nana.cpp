#include <vector>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int original_sum = 0;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                original_sum += i;
                sum += nums[i];
            }
            original_sum += nums.size();
            return original_sum - sum;
        }
    };