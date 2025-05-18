#!/usr/bin/env python3

from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        cache = {}
        def isWord(start: int) -> bool:
            if start in cache:
                return cache[start]
            for word in wordDict:
                if start + len(word) <= len(s) and s[start:start + len(word)] == word:
                    if start + len(word) == len(s):
                        return True
                    else:
                        if isWord(start + len(word)):
                            cache[start] = True
                            return True
            cache[start] = False
            return False
        
        return isWord(0)
        
s = "leetcode"
wordDict = ["leet","code"]
solution = Solution()
print(solution.wordBreak(s, wordDict))  # Output: True

s = "applepenapple"
wordDict = ["apple","pen"]
solution = Solution()
print(solution.wordBreak(s, wordDict))  # Output: True

s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]
solution = Solution()
print(solution.wordBreak(s, wordDict))  # Output: False

s = "cars"
wordDict = ["car","ca","rs"]
solution = Solution()
print(solution.wordBreak(s, wordDict))  # Output: True