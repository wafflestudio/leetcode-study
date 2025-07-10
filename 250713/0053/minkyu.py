class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        max_sum = nums[0]
        temp_sum = nums[0]
        for num in nums[1:]:
            temp_sum = max(temp_sum + num, num)
            if temp_sum > max_sum:
                max_sum = temp_sum
        return max_sum