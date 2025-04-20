#include <bits/stdc++.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <functional>
#include <string>

using namespace std;

vector<int> places{1, 10, 100, 1000, 10000, 100000};

class Solution {
public:
    void calulate_digit_count(string& s, unordered_map<int, int>& digit_count) {
        for (char c : s) {
            digit_count[c - '0'] += 2;
        }
    }

    int create_key(string& s, int mid) {
        int key = 0;
        for (int i = 0; i < mid; i++) {
            key += places[i] * s[i];
        }
        return key;
    }

    long long countGoodIntegers(const int n, const int k) {
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long long answer = 0;

        int upper_mid = (n + 1) / 2;
        int lower_mid = n / 2;
        const int END = pow(10, upper_mid);
        const int START = END / 10;

        unordered_set<string> visited;

        for (int i = START; i < END; i++) {
            unordered_map<int, int> digit_count;
            string s = to_string(i);
            string x_str(n, '0');
            for (int i = 0; i < upper_mid; i++) {
                x_str[i] = s[i];
                x_str[n - i - 1] = s[i];
            }
            long long x = stoll(x_str);

            if (x % k != 0) {
                continue;
            }

            string key(s);
            sort(key.begin(), key.begin() + lower_mid);
            if (visited.contains(key)) {
                continue;
            }

            visited.insert(key);

            calulate_digit_count(s, digit_count);
            if (n % 2 == 1) digit_count[s.back() - '0']--;

            long long denom = 1;
            for (auto& [digit, cnt] : digit_count) {
                denom *= factorial[cnt];
            }

            int temp = factorial[n] / denom;
            if (digit_count[0] > 0) {
                temp -= factorial[n - 1] / (denom / digit_count[0]);
            }
            answer += temp;
        }

        return answer;
    }
};

int main() {
    // fmt::println("{}", Solution().countGoodIntegers(5, 6));
    // fmt::println("{}", Solution().countGoodIntegers(1, 4));
    // fmt::println("{}", Solution().countGoodIntegers(4, 1));
    fmt::println("{}", Solution().countGoodIntegers(10, 1));
}
