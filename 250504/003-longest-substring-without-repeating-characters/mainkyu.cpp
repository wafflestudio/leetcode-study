#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // m[c] = i
        // i is the index of c in the string s
        unordered_map<char, int> m;

        int l = -1;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            char& c = s[i];

            auto match = m.find(c);
            if (match != m.end()) {
                int new_l = match->second;
                while (l < new_l) {
                    m.erase(m.find(s[++l]));
                }
            }
            m[c] = i;

            max_len = max(i - l, max_len);
        }
        return max_len;
    }
};

int main() {
    println("{}", Solution().lengthOfLongestSubstring("abcabcbb"));
}
