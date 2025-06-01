#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
    private:
        unordered_set<int> neg_set;
        unordered_set<int> pos_set;
        vector<int> neg_list;
        vector<int> pos_list;
        unordered_set<int> pair_set;
        int zeros = 0;
    
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> answer;
    
            for (auto num : nums) {
                if (num < 0) {
                    if (neg_set.find(num) == neg_set.end()) {
                        neg_set.insert(num);
                        neg_list.push_back(num);
                    } else {
                        pair_set.insert(num);
                    }
                } else if (num >= 0) {
                    if (num == 0) zeros++;
                    if (pos_set.find(num) == pos_set.end()) {
                        pos_set.insert(num);
                        pos_list.push_back(num);
                    } else {
                        pair_set.insert(num);
                    }
                }
            }
            sort(neg_list.begin(), neg_list.end());
            sort(pos_list.begin(), pos_list.end());
    
            for (int i = 0; i+1 < neg_list.size(); i++) {
                for (int j = i+1; j < neg_list.size(); j++) {
                    int neg_sum = neg_list[i] + neg_list[j];
                    if (pos_set.find(-neg_sum) != pos_set.end()) {
                        answer.push_back({ neg_list[i], neg_list[j], -neg_sum});
                    }
                }
            }
            for (int i = 0; i+1 < pos_list.size(); i++) {
                for (int j = i+1; j < pos_list.size(); j++) {
                    int pos_sum = pos_list[i] + pos_list[j];
                    if (neg_set.find(-pos_sum) != neg_set.end()) {
                        answer.push_back({ pos_list[i], pos_list[j], -pos_sum});
                    }
                }
            }
            for (auto pair : pair_set) {
                if (neg_set.find(-2*pair) != neg_set.end()) {
                    answer.push_back({ pair, pair, -2 * pair });
                }
                if (pos_set.find(-2*pair) != pos_set.end()) {
                    if (pair == 0) {
                        if (zeros >= 3) answer.push_back({ 0, 0, 0 });
                    } else {
                        answer.push_back({ pair, pair, -2 * pair });
                    }
                }
            }
    
            return answer;
        }
    };

// int main() {
//     Solution sol;
//     vector<int> nums = {0, 1, 0, -1};
//     auto res = sol.threeSum(nums);

//     for (auto& triplet : res) {
//         for (int val : triplet) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

