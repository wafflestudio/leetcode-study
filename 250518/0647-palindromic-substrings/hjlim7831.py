class Solution:
    def countSubstrings(self, s: str) -> int:
        answer = 0
        dp = [[False for _ in range(len(s))] for _ in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = True
        answer += len(s)
        
        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                answer += 1
            else:
                dp[i][i + 1]  = False
        
        for size in range(2, len(s)):
            for idx in range(len(s) - size):
                if dp[idx + 1][idx + size - 1] and s[idx] == s[idx + size]:
                    dp[idx][idx + size] = True
                    answer += 1
                else:
                    dp[idx][idx + size] = False
        return answer

        

        