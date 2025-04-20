class Solution(object):
    def countPaths(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        from collections import defaultdict

        graph = defaultdict(list)
        for u, v, t in roads:
            graph[u].append((v, t))
            graph[v].append((u, t))

        MOD = 10**9 + 7
        dist = [float("inf")] * n
        ways = [0] * n
        visited = [False] * n

        dist[0] = 0
        ways[0] = 1

        for _ in range(n):
            u = -1
            min_d = float("inf")
            for i in range(n):
                if not visited[i] and dist[i] < min_d:
                    min_d = dist[i]
                    u = i

            if u == -1:
                break

            visited[u] = True

            for v, t in graph[u]:
                if visited[v]:
                    continue
                new_d = dist[u] + t
                if new_d < dist[v]:
                    dist[v] = new_d
                    ways[v] = ways[u]
                elif new_d == dist[v]:
                    ways[v] = (ways[v] + ways[u]) % MOD

        return ways[n - 1]
