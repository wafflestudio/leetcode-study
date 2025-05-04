#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
      unordered_map<int, int> lines; // 값, 연속 개수
  
      int longestConsecutive(vector<int>& nums) {
          lines.reserve(nums.size()); // 성능 올리는 방법 -> umap의 버킷을 미리 할당
  
          int max_val = 0;
  
          for (int i = 0; i < nums.size(); i++) {
              int num = nums[i];
              if (lines.count(num))
                  continue;
  
              int left_size = 0, right_size = 0, ll, rr;
              if (lines.count(num - 1)) {
                  left_size = lines[num - 1];
                  ll = num - lines[num - 1];
              }
              if (lines.count(num + 1)) {
                  right_size = lines[num + 1];
                  rr = num + lines[num + 1];
              }
  
              int sum = left_size + right_size + 1;
              if (left_size && right_size) {
                  lines[ll] = sum;
                  lines[rr] = sum;
                  lines[num] = sum;
              } else if (left_size) {
                  lines[ll] = sum;
                  lines[num] = sum;
              } else if (right_size) {
                  lines[rr] = sum;
                  lines[num] = sum;
              } else {
                  lines[num] = sum;
              }
              // cout << num << " : " << sum << endl;
              max_val = max(max_val, sum);
          }
  
          return max_val;
      }
  };