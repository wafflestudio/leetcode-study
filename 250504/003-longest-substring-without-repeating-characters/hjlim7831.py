from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0

        cnt_dict = defaultdict(int)
        cnt_dict[s[0]] = 1
        st, ed = 0, 1
        answer = 1

        while ed < len(s):
            if cnt_dict[s[ed]] > 0:
                cnt_dict[s[st]] -= 1
                st += 1
            else:
                cnt_dict[s[ed]] += 1
                ed += 1
                answer = max(answer, ed - st)
        return answer