from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        intervals.sort()

        cursor = intervals[-1][0]
        count = 0

        for start, end in reversed(intervals[:-1]):
            if cursor < end:
                count += 1
            else:
                cursor = start

        return count

# 0 1 2 3 4 5 6
# |   |
#   |   |
#     |     |
#       |   |
#         |   |