from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        m = defaultdict(list)
        for s in strs:
            key = tuple(sorted(list(s)))
            m[key].append(s)
        return list(m.values())
