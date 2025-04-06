from functools import reduce
from itertools import combinations

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        if not nums:
            return 0
        answer = 0
        for n in range(1, len(nums) + 1):
            for subset in combinations(nums, n):
                answer += reduce(lambda x, y: x ^ y, subset)

        return answer
        