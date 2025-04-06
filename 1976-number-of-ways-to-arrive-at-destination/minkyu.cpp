#include <bits/stdc++.h>

using namespace std;

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int DIVISOR = 1'000'000'007;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int destination = n - 1;
        // graph[u][i] = (time, v) u번 노드에 연결되어 있는 i번째 도로는 v로
        // time만큼 걸리는 도로
        vector<vector<pair<int, int>>> graph(n);

        for (const vector<int>& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            graph[u].emplace_back(time, v);
            graph[v].emplace_back(time, u);
        }

        min_heap<pair<long long, int>> heap;
        vector<long long> sp(n, LLONG_MAX);
        vector<long long> num_of_sp(n, 0L);

        heap.emplace(0, 0);
        num_of_sp[0] = 1;

        while (!heap.empty()) {
            auto [time_sum, node] = heap.top();
            heap.pop();

            if (time_sum > sp[node])
                continue;

            for (auto [time, adj] : graph[node]) {
                long long new_time_sum = time_sum + time;
                if (new_time_sum < sp[adj]) {
                    sp[adj] = new_time_sum;
                    num_of_sp[adj] = num_of_sp[node];
                    heap.emplace(new_time_sum, adj);
                } else if (new_time_sum == sp[adj]) {
                    num_of_sp[adj] =
                        (num_of_sp[adj] + num_of_sp[node]) % DIVISOR;
                }
            }
        }

        return num_of_sp[destination];
    }
};
