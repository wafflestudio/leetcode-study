class Solution(object):
    def longestConsecutive(self, nums):
        if not nums:
            return 0

        nums_set = set(nums)

        max_len = 0
        for num in nums_set:
            if num - 1 in nums_set:
                continue

            cur_num = num
            cur_len = 1
            while cur_num + 1 in nums_set:
                cur_num += 1
                cur_len += 1

            max_len = max(max_len, cur_len)

        return max_len
