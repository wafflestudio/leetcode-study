from typing import List

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
      subsets = [0]
      for num in nums:
         size = len(subsets)
         for i in range(size):
            subsets.append(subsets[i] ^ num)
      return sum(subsets)


def test_case1():
   nums = [1, 3]
   expected = 6
   assert Solution().subsetXORSum(nums) == expected

def test_case2():
   nums = [5,1,6]
   expected = 28
   assert Solution().subsetXORSum(nums) == expected