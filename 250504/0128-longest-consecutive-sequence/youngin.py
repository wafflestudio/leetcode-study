from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        max_length = 0
        for n in nums:
            if n-1 in nums:
                continue
            length = 1
            while n + length in nums:
                length += 1
            max_length = max(max_length, length)

        return max_length

def test_case1():
    nums = [100,4,200,1,3,2]
    expected = 4
    assert Solution().longestConsecutive(nums) == expected