#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        for (char& c : t) {
            t_map[c]++;
        }
        unordered_map<char, int> visit;

        int left = 0;
        int remain = t.size();
        string answer = "";
        for (int right = 0; right < s.size(); right++) {
            char right_c = s[right];
            if (t_map[right_c] > visit[right_c]++) {
                remain--;
            }
            if (remain == 0) {
                int new_size = right + 1 - left;
                if (answer == "" || answer.size() > new_size) {
                    answer = s.substr(left, new_size);
                    println("new answer is : {}", answer);
                }

                // Why use "<=" instead of "<" in the condition?
                // Let's say s is "ab" and t is "b"
                // In that case, the answer is left = 1 and right = 1
                // If we use "<", we cannot reach the desired state.
                // If we use "<=", left becomes bigger than right by the time the inner loop finishes.
                // But it's fine because right is incremented at the end of the outer loop's iteration.
                for (; left <= right; left++) {
                    char left_c = s[left];
                    if (t_map[left_c] > --visit[left_c]) {
                        int new_size = right + 1 - left;
                        if (answer == "" || answer.size() > new_size) {
                            answer = s.substr(left, new_size);
                            println("new answer is : {}", answer);
                        }
                        remain++;
                        left++;
                        break;
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    // Solution().minWindow("ADOBECODEBANC", "ABC");
    Solution().minWindow("ab", "b");
    return 0;
}
