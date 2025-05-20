class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        rest = (len(nums) * (len(nums) + 1)) // 2
        for n in nums:
            rest -= n
        return rest