#!/usr/bin/env python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        dfs = []
        visited = {}

        dfs.append(node)
        visited[node] = Node(node.val)

        while(len(dfs) > 0):
            n = dfs.pop()
            for neighbor in n.neighbors:
                if neighbor not in visited:
                    visited[neighbor] = Node(neighbor.val)
                    dfs.append(neighbor)
                visited[n].neighbors.append(visited[neighbor])
        
        return visited[node]
