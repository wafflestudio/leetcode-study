class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        stack = [0]
        visited = [False] * (len(s) + 1)
        answer = False
        while stack:
            llim = stack.pop()
            if llim == len(s):
                answer = True
            for rlim in range(llim + 1, len(s) + 1):
                if s[llim:rlim] in wordSet and not visited[rlim]:
                    stack.append(rlim)
                    visited[rlim] = True
                    
        return answer