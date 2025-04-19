from collections import defaultdict
import math


class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        m = (n + 1) // 2
        palindromic_cases = [self.makePalindromic(str(i), n) for i in range(pow(10, m - 1), pow(10, m))]
        k_palindromic_cases = [x for x in palindromic_cases if int(x) % k == 0]

        uniq_candidates = set()
        for p in k_palindromic_cases:
            count_dict = defaultdict(int)
            for char in p:
                count_dict[char] += 1
            uniq_candidates.add(tuple(count_dict.get(str(i), 0) for i in range(10)))
        
        result = 0
        n_factorial = math.factorial(n)
        for candidate in uniq_candidates:
            rearrange_cases = n_factorial
            for c in candidate:
                rearrange_cases /= math.factorial(c)
            if candidate[0] > 0:
                zero_leading_cases = rearrange_cases / n * candidate[0]
                rearrange_cases -= zero_leading_cases
            result += int(rearrange_cases)
        return result
    
    def makePalindromic(self, n: str, size: int) -> str:
        if (size % 2 == 1):
            return n + n[:-1][::-1]
        else:
            return n + n[::-1]
    
def test_case_1():
    n = 3
    k = 5
    # 505 515 525 535 545 555 565 575 585 595
    # 1 + 2 + 8 * 3 = 27
    expected = 27
    assert Solution().countGoodIntegers(n, k) == expected

def test_case_2():
    # 4 8
    n = 1
    k = 4
    expected = 2
    assert Solution().countGoodIntegers(n, k) == expected

def test_case_3():
    n = 5
    k = 6
    expected = 2468
    assert Solution().countGoodIntegers(n, k) == expected