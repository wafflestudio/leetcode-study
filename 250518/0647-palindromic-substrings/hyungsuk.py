class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                substring = s[i : j + 1]
                if substring == substring[::-1]:
                    cnt += 1

        return cnt
