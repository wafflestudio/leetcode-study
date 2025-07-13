from collections import defaultdict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count_table = defaultdict(int)
        count_table[s[0]] += 1
        answer = 0

        left, right = 0, 0

        while left <= right and right < len(s):
            length = right - left + 1
            for key in count_table:
                if length - count_table[key] <= k:
                    answer = max(answer, length)
                    right += 1
                    if right >= len(s):
                        break
                    count_table[s[right]] += 1
                    break
            else:
                count_table[s[left]] -= 1
                left += 1

        return answer

