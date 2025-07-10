class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        intervals.sort()
        dp = [intervals[0]]
        for start, end in intervals[1:]:
            if start >= dp[-1][1]:
                dp.append([start, end])
            elif end < dp[-1][1]:
                dp[-1] = [start, end]
        
        return len(intervals) - len(dp)
    