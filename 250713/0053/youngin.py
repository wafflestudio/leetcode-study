from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        NEG_INF = -10^4 - 1
        dp = [NEG_INF] * len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(nums[i], dp[i - 1] + nums[i])
        return max(dp)