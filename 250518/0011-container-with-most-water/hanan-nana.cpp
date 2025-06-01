#include <algorithm>
#include <vector>
using namespace std;

class Solution {

    // how to maximaize gap * min(height of two)
    // 더 안쪽에 있고, 더 작은 막대는 무조건 더 안좋다.
    // 더 작은 쪽에서 옮겨가면서 확인한다. -> 둘다 같은 높이면 그보다 큰 값이 안쪽에 2개 이상 있어야 함 (즉 순서 상관 X)
    
    private:
        int calculateSize(int gap, int height1, int height2) {
            int min_height = min(height1, height2);
            return gap * min_height;
        }
    
    public:
        int maxArea(vector<int>& height) {
            int bar1 = 0, bar2 = height.size() - 1;
            int max_size = 0;
    
            while (bar1 != bar2) {
                max_size = max(max_size, calculateSize(bar2-bar1, height[bar1], height[bar2]));
    
                if (height[bar1] > height[bar2]) {
                    int i = 0;
                    while (height[bar2-i] <= height[bar2] && bar2-i != bar1) i++;
                    bar2 -= i;
                } else {
                    int i = 0;
                    while (height[bar1+i] <= height[bar1] && bar1+i != bar2) i++;
                    bar1 += i;
                }
            }
    
            return max_size;
        }
    };