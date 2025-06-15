#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer = nums[0];
        int neg_curr = 0;
        int pos_curr = 1;
        for (int& n: nums) {
            if (n > 0) {
                neg_curr *= n;
                pos_curr *= n;
                answer = max(answer, pos_curr);
            } else if (n < 0) {
                if (neg_curr != 0) {
                    int neg_old = neg_curr;
                    int pos_old = pos_curr;
                    neg_curr = pos_old * n;
                    pos_curr = neg_old * n;
                    answer = max(answer, pos_curr);
                } else {
                    neg_curr = pos_curr * n;
                    pos_curr = 1;
                    answer = max(answer, n);
                }
            } else {
                neg_curr = 0;
                pos_curr = 1;
                answer = max(answer, 0);
            }
        }
        return answer;
    }
};
