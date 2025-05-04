#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) return s;
        
        int max_l = 0;
        int max_r = 2;
        int l = max_l;
        int r = max_r;
        for (int i = 1; r < s.size(); ++i, ++l, ++r) {
            char& c = s[i];
            println("i, c : {}, {}", i, c);
            println("s[{}] == s[{}] : {} == {}", l, r, s[l], s[r]);
            if (s[l] == s[r]) {
                int temp_l = l;
                int temp_r = r;
                while (temp_l < temp_r && s[temp_l] == s[temp_r]) {++temp_l; --temp_r;}
                    println("temp_l, temp_r : {}, {}", temp_l, temp_r);
                if (temp_l == temp_r) {
                    while (l >= 0 && r < s.size() && s[l] == s[r]) {--l; ++r;}
                    println("l, r : {}, {}", l, r);
                    max_l = l;
                    max_r = r;
                }
            }
            println("");
        }

        l = 0;
        r = max_r - max_l - 1;
        for (int i = r / 2; r < s.size(); ++i, ++l, ++r) {
            char& c = s[i];
            if (s[l] == s[r]) {
                int temp_l = l;
                int temp_r = r;
                while (temp_l < temp_r && s[temp_l] == s[temp_r]) {++temp_l; --temp_r;}
                if (temp_l > temp_r) {
                    while (l >= 0 && r < s.size() && s[l] == s[r]) {--l; ++r;}
                    max_l = l;
                    max_r = r;
                }
            }
        }

        return s.substr(max_l + 1, max_r - max_l - 1);
    }
};

int main() {
    println("{}", Solution().longestPalindrome("aacabdkacaa"));
}