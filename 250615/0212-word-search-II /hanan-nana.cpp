#include <set>
#include <string>
#include <vector>
using namespace std;


class Solution {
    private:
        int ROW, COL;
        set<string> answer;
    
        struct TrieNode {
            TrieNode* children[26];
            bool isEnd;
            string word;
            
            TrieNode() {
                isEnd = false;
                for (int i = 0; i < 26; i++) children[i] = nullptr;
            }
        };
    
        class Trie {
            public:
                TrieNode* root;
    
                Trie() {
                    root = new TrieNode();
                }
    
                void insert(const string& word) {
                    TrieNode* cur = root;
                    for (auto c: word) {
                        if (cur->children[c-'a'] == nullptr) {
                            cur->children[c-'a'] = new TrieNode();
                        }
                        cur = cur->children[c-'a'];
                    }
                    cur->isEnd = true;
                    cur->word = word;
                }
        };
    
        void check(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, TrieNode* cur) {
            if (cur->isEnd) answer.insert(cur->word);
    
            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {1, 0, -1, 0};
    
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
    
                if (nx < 0 || nx >= ROW || ny < 0 || ny >= COL) continue;
                if (cur->children[board[nx][ny] -'a'] != nullptr && visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    check(board, visited, nx, ny, cur->children[board[nx][ny]-'a']);
                    visited[nx][ny] = false;
                }
            }
        }
    
    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            Trie trie;
            ROW = board.size();
            COL = board[0].size();
    
            for (auto word: words) {
                trie.insert(word);
            }
    
            vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    TrieNode* startNode = trie.root->children[board[i][j] - 'a'];
                    if (startNode) {
                        visited[i][j] = true;
                        check(board, visited, i, j, startNode);
                        visited[i][j] = false;
                    }
                }
            }
    
            return vector<string>(answer.begin(), answer.end());
        }
    };