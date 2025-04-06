class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # edge 정보로 graph 구성하기
        graph = [[] for _ in range(n)]
        for n1, n2 in edges:
            graph[n1].append(n2)
            graph[n2].append(n1)
        
        # 방문기록 남길 array
        visited = [False] * n

        # node들 그룹짓기
        connected_group = []
        for st in range(n):
            if visited[st]:
                continue
            visited[st] = True
            group = set([st])
            traverse(st, visited, graph, group)
            connected_group.append(group)
        
        # 각 그룹들이 서로 다 연결되어 있는지 확인
        answer = 0
        for group in connected_group:
            group_size = len(group)
            cnt = 0
            for node in group:
                cnt += len(graph[node])
            print(cnt, group_size)
            if group_size * (group_size - 1) == cnt:
                answer += 1
        
        return answer



def traverse(st, visited, graph, group):
    for ed in graph[st]:
        group.add(ed)
        if visited[ed]:
            continue
        visited[ed] = True
        traverse(ed, visited, graph, group)

    




