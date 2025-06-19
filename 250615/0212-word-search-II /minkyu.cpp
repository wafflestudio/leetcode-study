#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    bool is_word;
    bool visited;
    string word;
    unordered_map<char, TrieNode*> children;

    TrieNode()
        : is_word(false)
        , visited(false)
        , word("")
        , children() {};
};

class Solution {
public:
    // Improvement 1: It is essential to specify every non-primitive arguments as a reference variable, because the copy operation of huge variable costs really expensive.
    void collect(vector<vector<char>>& board, TrieNode*& prev, int x, int y, vector<string>& cum, int m, int n, int visited[12][12]) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) return;
        visited[x][y] = true;
        if (prev->children.contains(board[x][y])) {
            TrieNode* now = prev->children[board[x][y]];

            if (now->is_word && !now->visited) {
                cum.push_back(now->word);
                now->visited = true;
            }

            collect(board, now, x + 1, y, cum, m, n, visited);
            collect(board, now, x - 1, y, cum, m, n, visited);
            collect(board, now, x, y + 1, cum, m, n, visited);
            collect(board, now, x, y - 1, cum, m, n, visited);

            // Improvement 2: If the word is counted and this is a leaf node, remove the current node from the parent node.
            if (now->is_word && now->visited && now->children.empty()) {
                prev->children.erase(prev->children.find(board[x][y]));
            }
        }
        visited[x][y] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        TrieNode* word_trie = new TrieNode();

        for (string& word : words) {
            TrieNode* now = word_trie;
            for (char& c : word) {
                if (!now->children.contains(c)) {
                    now->children[c] = new TrieNode();
                }
                now = now->children[c];
            }
            now->is_word = true;
            now->word = word;
        }

        vector<string> answer;
        // Improvement 3: Use an array instead of a vector if the size of the array is fixed and unchangeable.
        int visited[12][12];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                collect(board, word_trie, i, j, answer, m, n, visited);
            }
        }
        return answer;
    }
};
