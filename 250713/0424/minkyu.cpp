#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int answer = 0;
        int left = 0;
        int right = 0;
        vector<bool> visited(128, false);
        vector<char> candiates;
        vector<int> count_of(128, 0);
        for (char& c: s) {
            char r_char = s[right++];
            if (!visited[r_char]) {
                visited[r_char] = true;
                candiates.push_back(r_char);
            }
            int temp = ++count_of[r_char] + k;
            int q_len = right - left;
            bool left_step_forward = true;
            if (temp < q_len) {
                for (char& candi: candiates) {
                    int temp = count_of[candi] + k;
                    if (temp >= q_len) {
                        left_step_forward = false;
                        break;
                    }
                }
            } else {
                left_step_forward = false;
            }
            if (left_step_forward) {
                count_of[s[left++]]--;
            }
        }
        return right - left;
    }
};

int main() {
    string s = "BAAAB";
    int k = 2;
    println("{}", Solution().characterReplacement(s, k));
}