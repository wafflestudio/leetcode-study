class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0

        max_length = 0
        used_char = set()

        left = 0
        for right in range(len(s)):
            while s[right] in used_char:
                used_char.remove(s[left])
                left += 1

            used_char.add(s[right])

            max_length = max(max_length, right - left + 1)

        return max_length
