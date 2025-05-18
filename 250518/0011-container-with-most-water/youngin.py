#!/usr/bin/env python3

from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = min(height[left], height[right]) * (right - left)
        while left < right:
            needCalculation = False
            if (height[left] < height[right]):
                left += 1
                if height[left] > height[left - 1]:
                    needCalculation = True
            else:
                right -= 1
                if height[right] > height[right + 1]:
                    needCalculation = True
            if needCalculation:
                max_area = max(max_area, min(height[left], height[right]) * (right - left))

        return max_area
    
# Test
if __name__ == "__main__":
    solution = Solution()
    print(solution.maxArea([1,8,6,2,5,4,8,3,7]))  # Output: 49
    print(solution.maxArea([1,1]))  # Output: 1
            