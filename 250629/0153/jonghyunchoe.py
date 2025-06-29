class Solution:
    def findMin(self, nums: List[int]) -> int:
        start = 0
        end = len(nums) - 1
        while start < end: 
            index = (start + end) // 2
            if nums[index] > nums[end]: 
                start = index + 1
            else: 
                end = index 
        return nums[start]