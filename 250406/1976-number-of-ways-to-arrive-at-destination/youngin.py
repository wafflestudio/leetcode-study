import heapq
from collections import defaultdict
from typing import List
import unittest

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        # Initialize the graph and the distance array
        INF = 10**10

        graph = defaultdict(list)
        for u, v, w in roads:
            graph[u].append((v, w))
            graph[v].append((u, w))

        min_time = [INF] * n
        ways = [0] * n
        min_time[0] = 0
        ways[0] = 1

        pq = [(0, 0)] # (time, node)
        while pq:
            time, node = heapq.heappop(pq)
            if time > min_time[node]:
                continue
            for neighbor, weight in graph[node]:
                new_time = time + weight
                if new_time < min_time[neighbor]:
                    min_time[neighbor] = new_time
                    ways[neighbor] = ways[node]
                    heapq.heappush(pq, (new_time, neighbor))
                elif new_time == min_time[neighbor]:
                    ways[neighbor] = (ways[neighbor] + ways[node]) % (10**9 + 7)

        return ways[-1]


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def testCase1(self):
        n = 7
        roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
        expected = 4
        self.assertEqual(self.s.countPaths(n, roads), expected)

    def testCase2(self):
        n = 2
        roads = [[1,0,10]]
        expected = 1
        self.assertEqual(self.s.countPaths(n, roads), expected)

