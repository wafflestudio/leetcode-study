class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        while start <= end: 
            index = (start + end) // 2
            if nums[index] == target:
                return index
            if nums[start] <= nums[index]:
                if nums[start] <= target < nums[index]:
                    end = index - 1
                else:
                    start = index + 1
            elif nums[index] <= nums[end]:
                if nums[index] < target <= nums[end]:
                    start = index + 1 
                else:
                    end = index - 1

        return -1