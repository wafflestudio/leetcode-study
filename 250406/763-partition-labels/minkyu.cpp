#include <bits/stdc++.h>
#include <ranges>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<long> end_map(200, -1);
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            long& last = end_map[c];
            if (last == -1)
                last = i;
        }

        vector<int> answer{0};
        for (auto [i, c] : ranges::views::enumerate(s)) {
            int& end = answer[answer.size() - 1];
            int new_end = end_map[c];
            if (i > end) {
                answer.push_back(new_end);
            } else if (new_end > end) {
                end = new_end;
            }
        }

        for (int i = answer.size() - 1; i > 0; --i) {
            answer[i] -= answer[i - 1];
        }
        answer[0] += 1;

        return answer;
    }
};
