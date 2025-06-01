#include <unordered_map>
#include <unordered_set>
#include <vector>

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



class Solution {
    private:
        unordered_map<int, Node*> node_list;
        unordered_set<int> visited;
    
        void AddNeighbor(Node* a, Node* b) {
            a->neighbors.push_back(b);
            b->neighbors.push_back(a);
        }
    
        // DFS
        // 우선 이웃 다 복사 (원래 없으면 생성해서), (방문한거면 생략)
        // 그다음 탐색 이어가기
    
        void DFS(Node* node) {
            // 현재 보고 있는 노드
            Node* cur = node_list[node->val];
    
            for (auto neighbor : node->neighbors) {
                if (node_list.find(neighbor->val) == node_list.end()) { // 실수
                    // 없는 경우, 새로 생성해서 추가
                    Node* copy = new Node(neighbor->val);
                    node_list.insert({copy->val, copy});
                    AddNeighbor(cur, copy);
                } else if (visited.find(neighbor->val) == visited.end()) {
                    // 있고 방문 안한 경우, 추가
                    Node* copy = node_list[neighbor->val];
                    AddNeighbor(cur, copy);
                }
            }
    
            for (auto neighbor: node->neighbors) {
                if (visited.find(neighbor->val) == visited.end()) {
                    // 아직 방문 안한 노드인 경우
                    visited.insert(neighbor->val);
                    DFS(neighbor);
                }
            }
        }
    
    
    public:
    
        Node* cloneGraph(Node* node) {
            if (node == nullptr) return nullptr;
    
            Node* start = new Node(node->val);
            node_list.insert({start->val, start});
            visited.insert(node->val);
            DFS(node);
    
            return start;
        }
    };