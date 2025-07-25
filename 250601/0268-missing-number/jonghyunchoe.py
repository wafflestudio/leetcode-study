class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # sort the list 
        nums.sort()
        
        for i in range(len(nums)):
            if nums[i] != i:
                return i
        return len(nums)
