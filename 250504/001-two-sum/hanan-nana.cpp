#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
      vector<int> twoSum(vector<int>& nums, int target) {
          ios::sync_with_stdio(false);
          cin.tie(nullptr);
  
          unordered_map<int, int> mp;
  
          for (int i = 0; i < nums.size(); i++) {
              if (mp.count(target - nums[i])) return { mp[target-nums[i]], i };
              else mp[nums[i]] = i;
          }
  
          return {};
      }
  };