class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams_table = {} 
        for i in range(len(strs)):
            anagram = {} 
            for j in range(len(strs[i])):
                if strs[i][j] not in anagram:
                    anagram[strs[i][j]] = 1 
                else:
                    anagram[strs[i][j]] += 1 

            anagram = frozenset(anagram.items())
            if anagram not in anagrams_table:
                anagrams_table[anagram] = []
                anagrams_table[anagram].append(strs[i])
            else:
                anagrams_table[anagram].append(strs[i]) 
        
        group_anagrams = [] 
        for key in anagrams_table:
            group_anagrams.append(anagrams_table[key])
        return group_anagrams
