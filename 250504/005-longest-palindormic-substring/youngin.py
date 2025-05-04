class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        palindrome = [[False for _ in range(n)] for _ in range(n)]
        track = [0, 0]

        for i in range(n):
            palindrome[i][i] = True
        
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                palindrome[i][i+1] = True
                track = [i, i + 1]

        for size in range(2, n):
            for i in range(n - size):
                if s[i] == s[i + size] and palindrome[i + 1][i + size - 1]:
                    palindrome[i][i + size] = True
                    track = [i, i + size]

        i, j = track
        return s[i: j + 1]

print(Solution().longestPalindrome("ccc") == "ccc")
print(Solution().longestPalindrome("babad") == "aba")
print(Solution().longestPalindrome("cbbd") == "bb")