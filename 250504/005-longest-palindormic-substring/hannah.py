class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        max_val = ""
        
        for i in range(len(s)):
            left, right = i, i
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            if len(s[left+1:right])> len(max_val):
                max_val = s[left+1:right]

            left, right = i, i+1
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            if len(s[left+1:right])> len(max_val):
                max_val = s[left+1:right]

        return max_val