"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""


class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return None

        # BFS
        visited = {}
        visited[node] = Node(node.val)
        Q = [node]
        while Q:
            current = Q.pop(0)
            for n in current.neighbors:
                if n not in visited:
                    visited[n] = Node(n.val)
                    Q.append(n)
                visited[current].neighbors.append(visited[n])

        return visited[node]
