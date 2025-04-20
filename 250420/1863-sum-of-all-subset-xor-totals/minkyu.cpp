#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> one(5, -1);
        vector<int> zero(5, 0);
        for (int num : nums) {
            for (int i = 0; i < 5; i++) {
                if (num % 2 == 0)
                    zero[i]++;
                else
                    one[i]++;
                num >>= 1;
            }
        }

        int answer = 0;
        for (int i = 0; i < 5; i++) {
            if (one[i] == -1) continue;
            cout << i << ' ' << one[i] << ' ' << zero[i] << endl;
            cout << (1 << i) << ' ' << one[i] << ' ' << (1 << zero[i]) << endl;
            cout << (1 << i) * one[i] * (1 << zero[i]) << endl << endl;
            answer += (1 << i) * (1 << one[i]) * (1 << zero[i]);
        }
        return answer;
    }
};

int main() {
    vector<int> nums {3,4,5,6,7,8};
    cout << Solution().subsetXORSum(nums) << endl;
    return 0;
}
