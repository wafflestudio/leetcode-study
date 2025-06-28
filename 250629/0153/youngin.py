from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)

        start = 0
        end = n - 1

        while start < end:
            mid = (start + end) // 2
            if nums[mid % n] >= nums[start % n]: # mid 안포함 오른쪽에 최솟값 존재 혹은 start가 최소
                if nums[start % n] < nums[(start - 1) % n]: # start가 최소인 경우
                    return nums[start]
                start = mid + 1
            else: # mid 포함 왼쪽에 최솟값 존재, start는 아님
                start = start + 1
                end = mid
        return nums[end]

