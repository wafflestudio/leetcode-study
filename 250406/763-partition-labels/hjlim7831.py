class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_occur = {}
        for i, char in enumerate(s):
            last_occur[char] = i
        
        result = []
        start = 0
        end = 0

        for i, char in enumerate(s):
            end = max(end, last_occur[char])

            if i == end:
                result.append(end - start + 1)
                start = i + 1
        
        return result