#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int answer = min(k, (int) s.size());
        for (char target = 'A'; target <= 'Z'; target++) {
            queue<char> q;
            int rem = k;
            for (char& c : s) {
                if (c == target) {
                    q.push(c);
                } else {
                    if (rem > 0) {
                        q.push(c);
                        rem--;
                    } else {
                        answer = max(answer, (int) q.size());
                        while (!q.empty()) {
                            char out = q.front();
                            q.pop();
                            if (out != target) {
                                q.push(c);
                                break;
                            }
                        }
                    }
                }
            }
            answer = max(answer, (int) q.size());
        }
        return answer;
    }
};

int main() {
    string s = "ABBB";
    int k = 2;
    println("{}", Solution().characterReplacement(s, k));
}