from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)

        start = 0
        end = n - 1

        while start <= end:
            mid = (start + end) // 2
            if nums[start] == target:
                return start
            if nums[end] == target:
                return end
            if nums[mid] == target:
                return mid

            if nums[start % n] <= nums[mid % n]:
                if nums[start % n] < target < nums[mid % n]: # mid 왼쪽 파트는 ascending일 수 밖에
                    start = start + 1
                    end = mid - 1
                else:
                    start = mid + 1
                    end = end - 1
            else:
                if nums[mid % n] < target < nums[end % n]: # mid 오른쪽 파트는 ascending일 수 밖에
                    start = mid + 1
                    end = end - 1
                else:
                    start = start + 1
                    end = mid - 1

        return -1