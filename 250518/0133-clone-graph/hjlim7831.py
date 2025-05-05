"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        self.answer = None
        self.nodes = [Node(i) for i in range(101)]
        self.visited = [False] * 101

        self.dfs(node)

        return self.answer
    
    def dfs(self, curr: Optional['Node']):
        if not curr:
            return
        if self.visited[curr.val]:
            return
        self.visited[curr.val] = True
        curr_copy = self.nodes[curr.val]
        if not self.answer:
            self.answer = curr_copy
        if curr.neighbors:
            curr_copy.neighbors = []
            for next_node in curr.neighbors:
                curr_copy.neighbors.append(self.nodes[next_node.val])
            for next_node in curr.neighbors:
                self.dfs(next_node)