#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        vector<int> count_of(128, 0);
        int max_count = 0;
        for (char& c: s) {
            max_count = max(max_count, ++count_of[s[right++]]);
            if (max_count + k < right - left) {
                count_of[s[left++]]--;
            }
        }
        return right - left;
    }
};

int main() {
    string s = "AABABBA";
    int k = 1;
    println("{}", Solution().characterReplacement(s, k));
}