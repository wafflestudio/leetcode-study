#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#include <print>

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        queue<Node*> q;
        q.push(node);
        vector<Node*> copys(101);
        vector<bool> visit(101, false);
        for (int i = 1; i < 101; i++) {
            copys[i] = new Node(i);
        }
        auto answer = copys[node->val];
        visit[node->val] = true;

        while (!q.empty()) {
            auto original = q.front(); q.pop();
            auto& copy = copys[original->val];
            for (auto& neighbor : original->neighbors) {
                auto& neighbor_copy = copys[neighbor->val];
                copy->neighbors.push_back(neighbor_copy);
                if (!visit[neighbor->val]) {
                    q.push(neighbor);
                    visit[neighbor->val] = true;
                };
            }
        }

        return answer;
    }
};
