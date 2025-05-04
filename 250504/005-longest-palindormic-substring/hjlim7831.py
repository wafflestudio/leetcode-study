class Solution:
    def longestPalindrome(self, s: str) -> str:
        answer = s[0]
        # 홀수 케이스
        for center in range(len(s)):
            st, ed = center - 1, center + 1
            str_len = 1
            while st >= 0 and ed < len(s):
                if s[st] != s[ed]:
                    break
                str_len += 2
                if len(answer) < str_len:
                    answer = s[st:ed+1]
                st -= 1
                ed += 1

        # 짝수 케이스
        for idx in range(len(s)-1):
            if s[idx] != s[idx+1]:
                continue
            str_len = 2
            if len(answer) < str_len:
                answer = s[idx:idx+2]
            st, ed = idx -1, idx + 2
            while st >= 0 and ed < len(s):
                if s[st] != s[ed]:
                    break
                str_len += 2
                if len(answer) < str_len:
                    answer = s[st:ed+1]
                st -= 1
                ed += 1
        return answer