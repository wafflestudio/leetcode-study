#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // index on last visit
        // use fixed-length array because each character of s is ascii
        int pos[128];
        memset(pos, -1, sizeof(pos));

        int l = -1;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            char& c = s[i];
            l = max(l, pos[c]);
            pos[c] = i;
            max_len = max(max_len, i - l);
        }
        
        max_len = max(max_len, (int) s.size() - l - 1);
        return max_len;
    }
};

int main() {
    println("{}", Solution().lengthOfLongestSubstring("cdmyhietzgalfkjindktzztkpcfghxblaqjjypezweldqwmgcyzbytnn"));
}
