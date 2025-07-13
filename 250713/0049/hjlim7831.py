class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        table = {}

        for s in strs:
            key = "".join(sorted(s))
            if key not in table:
                table[key] = []
            table[key].append(s)
        
        answer = []
        for k in table:
            answer.append(table[k])
        return answer
        