class Solution:
    divisor = 10 ** 9 + 7
    def countGoodNumbers(self, n: int) -> int:
        even_cases = 5 # 0 2 4 6 8
        prime_cases = 4 # 2 3 5 7

        odd_index_count = n // 2
        even_index_count = n - odd_index_count

        return (pow(even_cases, even_index_count, self.divisor) * pow(prime_cases, odd_index_count, self.divisor)) % self.divisor

def test_case1():
    n = 1
    expected = 5
    assert Solution().countGoodNumbers(n) == expected

def test_case2():
    n = 4
    expected = 400
    assert Solution().countGoodNumbers(n) == expected

def test_case3():
    n = 50
    expected = 564908303
    assert Solution().countGoodNumbers(n) == expected
