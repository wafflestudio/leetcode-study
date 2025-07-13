from collections import defaultdict


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = defaultdict(int)

        left = 0
        max_freq = 0
        max_len = 0

        for right in range(len(s)):
            freq[s[right]] += 1
            max_freq = max(max_freq, freq[s[right]])

            if max_freq + k < right - left + 1:
                freq[s[left]] -= 1
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len
