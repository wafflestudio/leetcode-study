class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        palindrome = [[False for _ in range(len(s))] for _ in range(n)]
        answer = 0
        for i in range(n):
            palindrome[i][i] = True
            answer += 1
        
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                palindrome[i][i + 1] = True
                answer += 1
            else:
                palindrome[i][i + 1] = False

        for size in range(2, n):
            for i in range(n - size):
                if s[i] == s[i + size] and palindrome[i + 1][i + size - 1]:
                    palindrome[i][i + size] = True
                    answer += 1

        return answer        