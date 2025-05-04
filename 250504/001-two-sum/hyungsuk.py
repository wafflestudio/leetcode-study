class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        candidates = {}
        for idx, num in enumerate(nums):
            if num in candidates:
                return [candidates[num], idx]
            else:
                candidates[target - num] = idx
