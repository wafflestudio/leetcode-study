from itertools import combinations
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = set()
        neg = []
        neg_set = set()
        zero = []
        pos = []
        pos_set = set()
        for num in nums:
            if num < 0:
                neg.append(num)
                neg_set.add(num)
            else:
                if num == 0:
                    zero.append(num)
                pos.append(num)
                pos_set.add(num)

        for i, j in combinations(pos, 2):
            if -(i + j) in neg_set:
                result.add(tuple(sorted([i, j, -(i + j)])))
        for i, j in combinations(neg, 2):
            if -(i + j) in pos_set:
                result.add(tuple(sorted([i, j, -(i + j)])))
        if len(zero) >= 3:
            result.add((0, 0, 0))
        return [list(t) for t in result]

