class Solution(object):
    def countCompleteComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = [[] for __ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        def dfs(node, component):
            visited[node] = True
            component.append(node)
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    dfs(neighbor, component)

        visited = [False] * n
        count = 0

        for i in range(n):
            if not visited[i]:
                component = []
                dfs(i, component)

                # Check
                vertices = len(component)
                edge_count = sum(len(graph[v]) for v in component) // 2

                if edge_count == vertices * (vertices - 1) // 2:
                    count += 1

        return count
