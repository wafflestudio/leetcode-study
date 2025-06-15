from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        dp_pos = [-2 ** 31] * n
        dp_neg = [2 ** 31] * n
        for i in range(n):
            if i == 0:
                if nums[i] >= 0:
                    dp_pos[i] = nums[i]
                else:
                    dp_neg[i] = nums[i]
            else:
                if dp_pos[i - 1] >= 0:
                    cal = dp_pos[i - 1] * nums[i]
                    if cal < 0:
                        dp_neg[i] = min(cal, nums[i])
                    else:
                        dp_pos[i] = max(cal, nums[i])
                if dp_neg[i - 1] < 0:
                    cal = dp_neg[i - 1] * nums[i]
                    if cal < 0:
                        dp_neg[i] = min(cal, nums[i])
                    else:
                        dp_pos[i] = max(cal, nums[i])
                if nums[i] >= 0:
                    dp_pos[i] = max(dp_pos[i], nums[i])
                else:
                    dp_neg[i] = min(dp_neg[i], nums[i])

        max_product = max(dp_pos)
        if max_product < 0:
            for i in range(n):
                if dp_neg[i] < 0:
                    max_product = max(max_product, dp_neg[i])

        return max_product
