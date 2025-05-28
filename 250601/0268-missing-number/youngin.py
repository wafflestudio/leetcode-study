from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        s = set([x for x in range(n + 1)])

        for num in nums:
            s.remove(num)

        return s.pop()
