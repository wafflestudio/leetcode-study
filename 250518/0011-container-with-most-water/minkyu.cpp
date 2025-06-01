#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int answer = 0;
        while (left < right) {
            answer = max(answer, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) left++;
            else right--;
        }
        return answer;
    }
};