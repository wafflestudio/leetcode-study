#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool bfs(int start, const vector<vector<int>>& graph, vector<bool>& visit) {
        int adj_count = graph[start].size();
        int point_count = 0;

        queue<int> q;
        q.push(start);
        visit[start] = true;
        bool complete = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            point_count++;

            for (const int& adj : graph[node]) {
                if (visit[adj])
                    continue;
                q.push(adj);
                visit[adj] = true;
                if (graph[adj].size() != adj_count)
                    complete = false;
            }
        }

        return complete && (adj_count == (point_count - 1));
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visit(n, false);
        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (visit[i])
                continue;
            if (bfs(i, graph, visit))
                answer++;
        }

        return answer;
    }
};
