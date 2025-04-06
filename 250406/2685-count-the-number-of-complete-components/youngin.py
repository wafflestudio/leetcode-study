from collections import defaultdict
from typing import List
import unittest

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # connect graph 찾기
        visited = set()
        components = []
        for node in range(n):
            if node not in visited:
                stack = [node]
                component = []
                while stack:
                    curr = stack.pop()
                    if curr not in visited:
                        visited.add(curr)
                        component.append(curr)
                        stack.extend(graph[curr])
                components.append(component)

        # 그리고 각 component에 대해 완전 그래프인지 확인
        complete_count = 0
        for component in components:
            size = len(component)
            if size == 1:
                complete_count += 1
            else:
                expected_edges_count = size * (size - 1)
                actual_edges_count = 0
                for node in component:
                    actual_edges_count += len(graph[node])
                if actual_edges_count == expected_edges_count:
                    complete_count += 1

        return complete_count


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def testCase1(self):
        n = 6
        edges = [[0,1],[0,2],[1,2],[3,4]]
        expected = 3
        self.assertEqual(self.s.countCompleteComponents(n, edges), expected)

    def testCase2(self):
        n = 6
        edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
        expected = 1
        self.assertEqual(self.s.countCompleteComponents(n, edges), expected)

