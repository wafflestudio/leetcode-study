from typing import List

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        # 정렬
        nums.sort()

        # dp table 생성
        n = len(nums)
        max_table = [0 for _ in range(n)]
        tracking_index = [-1 for _ in range(n)] 

        # dp 돌기
        for i in range(n):
            m = 0
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if max_table[j] >= m:
                        tracking_index[i] = j
                        m = max_table[j]
                        max_table[i] = max_table[j] + 1

        index = max(range(n), key=lambda i: max_table[i])

        res = []
        while(index >= 0):
            res.append(nums[index])
            index = tracking_index[index]    
        res.reverse()
        return res

def test_case1():
    nums = [1, 2, 3]
    expected = [1, 2]
    assert Solution().largestDivisibleSubset(nums) == expected

def test_case2():
    nums = [1, 2, 4, 8]
    expected = [1, 2, 4, 8]
    assert Solution().largestDivisibleSubset(nums) == expected

def test_case3():
    nums = [3,17]
    expected = [3]
    assert Solution().largestDivisibleSubset(nums) == expected

def test_case4():
    nums = [2, 4,8,10,240]
    expected = [2, 4,8,240]
    assert Solution().largestDivisibleSubset(nums) == expected

