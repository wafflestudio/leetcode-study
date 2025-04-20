#include <vector>

using namespace std;

class Solution {
  public:
      int answer = 0;
  
      // i 번째의 가능한 경우 진행
      void getXOR(int cur, int i, vector<int>& nums, int m) {
          if (i == m) return;
  
          int val = cur ^ nums[i];
          answer += val;
          getXOR(cur, i+1, nums, m);
          getXOR(val, i+1, nums, m);
      }
  
      int subsetXORSum(vector<int>& nums) {
          getXOR(0, 0, nums, nums.size());
          return answer;
      }
  };