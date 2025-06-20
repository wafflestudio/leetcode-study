#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void update_board(vector<vector<int>>& heights, int (*board)[200], int x, int y, int m, int n, int prev) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (board[x][y]) return;
        if (heights[x][y] < prev) return;
        board[x][y] = true;
        update_board(heights, board, x+1, y, m, n, heights[x][y]);
        update_board(heights, board, x-1, y, m, n, heights[x][y]);
        update_board(heights, board, x, y+1, m, n, heights[x][y]);
        update_board(heights, board, x, y-1, m, n, heights[x][y]);
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        int pacific[200][200];
        memset(pacific, false, 200 * 200 * sizeof(int));
        int atlantic[200][200];
        memset(atlantic, false, 200 * 200 * sizeof(int));

        for (int i = 0, j = 0; i < m; ++i) {
            update_board(heights, pacific, i, j, m, n, -1);
        }

        for (int i = 0, j = 0; j < n; ++j) {
            update_board(heights, pacific, i, j, m, n, -1);
        }

        for (int i = 0, j = n - 1; i < m; ++i) {
            update_board(heights, atlantic, i, j, m, n, -1);
        }

        for (int i = m - 1, j = 0; j < n; ++j) {
            update_board(heights, atlantic, i, j, m, n, -1);
        }

        vector<vector<int>> answer;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    answer.push_back({i ,j});
                }
            }
        }
        return answer;
    }
};

int main() {
    vector<vector<int>> heights {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    auto answer = Solution().pacificAtlantic(heights);
    for (auto& x: answer) {
        print("({}, {}), ", x[0], x[1]);
    }
}
