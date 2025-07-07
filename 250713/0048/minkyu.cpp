#include <bits/stdc++.h>
#include <iterator>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int two_c = n - 1;
        int x_max = (int) ceil(n / 2.0);
        int y_max = (int) ceil((n - 1) / 2.0);
        int old_x, old_y, new_x, new_y, old_value;
        for (int x = 0; x < x_max; x++) {
            for (int y = 0; y < y_max; y++) {
                old_value = matrix[x][y];
                old_x = x;
                old_y = y;
                for (int i = 0; i < 4; i++) {
                    new_x = old_y;
                    new_y = two_c - old_x;
                    swap(old_value, matrix[new_x][new_y]);
                    old_x = new_x;
                    old_y = new_y;
                }
            }
        }
    }

    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
