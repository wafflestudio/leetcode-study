#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int answer = s.size();
        for (int i = 0; i < s.size() - 1; i++) {
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < s.size() && s[l--] == s[r++]) answer++;

            l = i;
            r = i+1;
            while (l >= 0 && r < s.size() && s[l--] == s[r++]) answer++;
        }
        return answer;
    }
};