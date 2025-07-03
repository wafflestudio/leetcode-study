from bisect import bisect_left


class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        dp = [1] * len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
    
    def lengthOfLIS2(self, nums: list[int]) -> int:
        lis = [nums[0]]
        for num in nums:
            idx = bisect_left(lis, num)
            if idx == len(lis) and num > lis[-1]:
                lis.append(num)
            else:
                lis[idx] = num
        return len(lis)
