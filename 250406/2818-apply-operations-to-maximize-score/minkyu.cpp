#include <bits/stdc++.h>
#include <ranges>

using namespace std;

constexpr int DIVISOR = 1e9 + 7;

long long mod_pow(long long base, long long exp) {
    long long result = 1;
    long long temp = base % DIVISOR;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= temp;
            result %= DIVISOR;
        }
        temp *= temp;
        temp %= DIVISOR;
        exp /= 2;
    }
    return result;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> prime(1e5 + 1, 0);
        for (int i = 2; i <= 1e5; ++i) {
            if (prime[i] != 0)
                continue;
            for (int j = i; j <= 1e5; j += i) {
                prime[j] += 1;
            }
        }

        vector<int> dp(nums.size());
        priority_queue<tuple<int, int, size_t>> pq;
        for (auto [i, n] : ranges::views::enumerate(nums)) {
            int p = prime[n];
            dp[i] = p;
            pq.push({n, p, i});
        }

        long long score = 1;

        while (!pq.empty()) {
            auto [num, pnum, idx] = pq.top();
            pq.pop();
            if (num == 1)
                break;
            int left = idx - 1;
            while (left >= 0 && dp[left] < pnum)
                --left;
            int right = idx + 1;
            while (right < nums.size() && dp[right] <= pnum)
                ++right;
            long long count = (idx - left) * (right - idx);

            if (k > count) {
                k -= count;
                long long result = mod_pow(num, count);
                score *= result;
                score %= DIVISOR;
            } else {
                count = k;
                long long result = mod_pow(num, count);
                score *= result;
                score %= DIVISOR;
                break;
            }
        }

        return score;
    }
};
