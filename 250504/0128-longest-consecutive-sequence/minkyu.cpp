#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // m[num] = {num_end, num_start}
        // start = last element of max-length array where num is first element;
        // end = first element of max-length array where num is last element;
        unordered_map<int, pair<int, int>> m;

        for (int num : nums) {
            pair<int, int> se;
            if (!m.contains(num)) {
                m[num] = {num, num};
            }

            int left, right;
            left = right = num;
            if (m.contains(num + 1)) right = num + 1;
            if (m.contains(num - 1)) left = num - 1;

            auto [r_end, _] = m[right];
            auto [r_end_end, r_end_start] = m[r_end];
            auto [_, l_start] = m[left];
            auto [l_start_end, l_start_start] = m[l_start];

            m[r_end] = {r_end_end, min(r_end_start, l_start)};
            m[l_start] =  {max(l_start_end, r_end), l_start_start};
        }

        int answer = 0;
        for (auto [k, v] : m) {
            auto [s, e] = v;
            answer = max(answer, s - e + 1);
        }

        return answer;
    }
};

int main() {
    vector<int> nums{4, 2, 2, -4, 0, -2, 4, -3, -4, -4, -5, 1, 4, -9, 5, 0, 6, -8, -1, -3, 6, 5, -8, -1, -5, -1, 2, -9, 1};
    println("{}", Solution().longestConsecutive(nums));
}
