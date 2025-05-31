class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        d = [False] * (len(s) + 1)
        d[0] = True

        for i in range(1, len(s) + 1):
            for j in range(i):
                if d[j] is True and s[j:i] in wordDict:
                    d[i] = True
                    break

        return d[len(s)]
