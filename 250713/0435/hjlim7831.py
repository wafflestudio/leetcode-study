class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        answer = 0
        intervals.sort(key=lambda x: x[1])

        prev_end = intervals[0][1]

        for start, end in intervals[1:]:
            if start < prev_end:
                answer += 1
            else:
                prev_end = end
        
        return answer
            