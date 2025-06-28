from typing import List


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        r = len(heights)
        c = len(heights[0])

        pacific = set()
        atlantic = set()
        visited = set()

        for i in range(c):
            pacific.add((0, i))
            atlantic.add((r-1, i))
        for i in range(r):
            pacific.add((i, 0))
            atlantic.add((i, c-1))

        def safe_get(grid, i, j):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]):
                return grid[i][j]
            return 10 ** 5 + 1

        def dfs(x: int, y: int):
            if x < 0 or y < 0 or x > r-1 or y > c-1 or (x, y) in visited: return
            if (x, y) in atlantic and (x, y) in pacific: return
            h = heights[x][y]
            visited.add((x, y))

            if h >= safe_get(heights, x-1, y):
                dfs(x-1, y)
                if (x-1, y) in pacific:
                    pacific.add((x, y))
                if (x-1, y) in atlantic:
                    atlantic.add((x, y))
            if h >= safe_get(heights, x+1, y):
                dfs(x+1, y)
                if (x+1, y) in pacific:
                    pacific.add((x, y))
                if (x+1, y) in atlantic:
                    atlantic.add((x, y))
            if h >= safe_get(heights, x, y+1):
                dfs(x, y+1)
                if (x, y+1) in pacific:
                    pacific.add((x, y))
                if (x, y+1) in atlantic:
                    atlantic.add((x, y))
            if h >= safe_get(heights, x, y-1):
                dfs(x, y-1)
                if (x, y-1) in pacific:
                    pacific.add((x, y))
                if (x, y-1) in atlantic:
                    atlantic.add((x, y))

            visited.remove((x, y))

        for i in range(r):
            for j in range(c):
                dfs(i, j)

        return [list(t) for t in pacific & atlantic]