class Solution(object):
    def pacificAtlantic(self, heights):
        directions = [(-1,0), (1,0), (0,-1), (0,1)]
        r, c = len(heights), len(heights[0])
        pacific = [[0] * c for _ in range(r)]
        atlantic = [[0] * c for _ in range(r)]

        def dfs(i, j, visited):
            visited[i][j] = 1
            for di, dj in directions:
                ci, cj = i + di, j + dj
                if 0 <= ci < r and 0 <= cj < c:
                    if not visited[ci][cj] and heights[ci][cj] >= heights[i][j]:
                        dfs(ci, cj, visited)
        
        for i in range(r):
            dfs(i, 0, pacific)
            dfs(i, c - 1, atlantic)

        for j in range(c):
            dfs(0, j, pacific)
            dfs(r - 1, j, atlantic)

        result = []
        for i in range(r):
            for j in range(c):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])
        
        return result
