from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        start = 0
        end = 0

        for i in range(len(s)):
            dup_index = s[start: end].find(s[i])
            if dup_index == -1:
                end += 1
            else:
                max_length = max(max_length, end - start)
                start = start + dup_index + 1
                end += 1
        max_length = max(max_length, end - start)
        
        return max_length
