from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
        
        return [0, 1] # cannot reach

def test_case1():
    nums = [2,7,11,15]
    target = 9
    expected = [0,1]
    assert Solution().twoSum(nums, target) == expected

def test_case2():
    nums = [3,2,4], target = 6
    expected = [1,2]
    assert Solution().twoSum(nums, target) == expected

def test_case3():
    nums = [3,3], target = 6
    expected = [0,1]
    assert Solution().twoSum(nums, target) == expected