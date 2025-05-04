class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for idx, num in enumerate(nums):
            if target - num in nums:
                if target - num == num:
                    vals = nums[idx+1:]
                    if num in vals:
                        return [idx, idx+1+vals.index(target-num)]
                else:
                    return [idx, nums.index(target-num)]