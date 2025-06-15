#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    bool is_word;
    bool visited;
    string word;
    unordered_map<char, Node*> children;

    Node()
        : is_word(false)
        , visited(false)
        , word("")
        , children() {};
};

class Solution {
public:
    void collect(vector<vector<char>>& board, Node* prev, int x, int y, vector<string>& cum, int m, int n, set<pair<int, int>> visited) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited.contains({x, y})) return;
        visited.emplace(x, y);
        if (prev->children.contains(board[x][y])) {
            Node* now = prev->children[board[x][y]];
            if (now->is_word && !now->visited) {
                cum.push_back(now->word);
                now->visited = true;
            }
            collect(board, now, x+1, y, cum, m, n, visited);
            collect(board, now, x-1, y, cum, m, n, visited);
            collect(board, now, x, y+1, cum, m, n, visited);
            collect(board, now, x, y-1, cum, m, n, visited);
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        Node* word_tree = new Node();

        for (string& word : words) {
            Node* now = word_tree;
            for (char& c : word) {
                if (!now->children.contains(c)){
                    now->children[c] = new Node();
                }
                now = now->children[c];
            }
            now->is_word = true;
            now->word = word;
        }

        vector<string> answer;
        set<pair<int, int>> visited;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited.clear();
                collect(board, word_tree, i, j, answer, m, n, visited);
            }
        }
        return answer;
    }
};
