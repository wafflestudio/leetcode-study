import heapq

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        MOD = 10**9 + 7
        graph = {i: [] for i in range(n)}
        for st, ed, w in roads:
            graph[st].append((ed, w))
            graph[ed].append((st, w))
        
        min_heap = [(0, 0)]
        dist = [float('inf')] * n
        dist[0] = 0
        count = [0] * n
        count[0] = 1
        while min_heap:
            cur_time, node = heapq.heappop(min_heap)
            if cur_time > dist[node]:
                continue
            for neighbor, travel_time in graph[node]:
                new_time = cur_time + travel_time

                if new_time < dist[neighbor]:
                    dist[neighbor] = new_time
                    count[neighbor] = count[node]
                    heapq.heappush(min_heap, (new_time, neighbor))
                elif new_time == dist[neighbor]:
                    count[neighbor] = (count[neighbor] + count[node]) % MOD
        return count[n-1]