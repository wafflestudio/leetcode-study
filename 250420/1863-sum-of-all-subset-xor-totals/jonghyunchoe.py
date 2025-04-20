from itertools import combinations 

class Solution(object):
    def subsetXORSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        subsets = []
        for i in range(len(nums)+1):
            for combination in combinations(nums, i):
                subsets.append(list(combination)) 
        
        sum = 0
        for i in range(len(subsets)):
            sum += self.XOR(subsets[i])
        return sum

    def XOR(self, nums):
        if len(nums) == 0:
            return 0 

        result = 0   
        for num in nums:
            result = result ^ num
        
        return result 