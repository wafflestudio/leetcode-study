#include <cmath>

class Solution {
public:

    // 짝수인덱스에서 짝수, 홀수 인덱스에서 소수

    // 짝수 인덱스 -> 5개 가능, (N+1)/2
    // 홀수 인덱스 -> 4개 가능, N/2

    static long long mod_pow(long long base, long long exp, long long DIV_BY) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % DIV_BY;
            exp /= 2;
            base = (base * base) % DIV_BY;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long DIV_BY = 1e9+7;
        return (mod_pow(5, (n+1)/2, DIV_BY) * mod_pow(4, n/2, DIV_BY)) % DIV_BY;
    }
};