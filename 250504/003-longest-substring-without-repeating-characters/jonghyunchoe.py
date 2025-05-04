class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longestLength = 0
        for i in range(len(s)):
            characters = set()
            for j in range(i, len(s)):
                if s[j] in characters:
                    break 
                else:
                    characters.add(s[j])
            if len(characters) > longestLength:
                longestLength = len(characters)
        
        return longestLength 