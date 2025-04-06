import heapq
from collections import defaultdict
from typing import List
import unittest

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        state = defaultdict(lambda: (10**9, -10**9))
        for i, elem in enumerate(s):
            min_val = min(state[elem][0], i)
            max_val = max(state[elem][1], i)
            state[elem] = (min_val, max_val)

        pq = list(state.values())
        min_idx, max_idx = heapq.heappop(pq)
        partition_length = []
        while pq:
            curr_min_idx, curr_max_idx = heapq.heappop(pq)
            if max_idx < curr_min_idx:
                partition_length.append(max_idx - min_idx + 1)
                min_idx = curr_min_idx
                max_idx = curr_max_idx
            else:
                max_idx = max(max_idx, curr_max_idx)
        partition_length.append(max_idx - min_idx + 1)
        return partition_length



class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def testCase1(self):
        s = "ababcbacadefegdehijhklij"
        expected = [9, 7, 8]
        self.assertEqual(self.s.partitionLabels(s), expected)

    def testCase2(self):
        s = "eccbbbbdec"
        expected = [10]
        self.assertEqual(self.s.partitionLabels(s), expected)
