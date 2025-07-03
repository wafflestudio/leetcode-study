#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(string s, int k, int l) {
        queue<char> q;
        vector<int> count_of(26, 0);
        for (int i = 0; i < l; i++) {
            q.push(s[i]);
            int count = ++count_of[s[i] - 'A'];
            if (count + k >= l) return true;
        }
        for (int i = l; i < s.length(); i++) {
            char c = q.front(); q.pop();
            q.push(s[i]);
            --count_of[c - 'A'];
            int count = ++count_of[s[i] - 'A'];
            if (count + k >= l) return true;
            
        }
        return false;
    }

    int characterReplacement(string s, int k) {
        int left = min(k, (int) s.length());
        int right = s.length() + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(s, k, mid)) left = mid + 1;
            else right = mid;
        }
        return left - 1;
    }
};

int main() {
    string s = "ABBB";
    int k = 2;
    println("{}", Solution().characterReplacement(s, k));
}