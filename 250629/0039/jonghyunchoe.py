class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        self.backtrack(candidates, target, result, 0, [], 0)
        return result 

    def backtrack(self, candidates, target, working_set, value, combination, index):
        if value == target:
            working_set.append(combination[:])
            return 
        elif value > target:
            return 
        
        for i in range(index, len(candidates)):
            combination.append(candidates[i]) 
            self.backtrack(candidates, target, working_set, value + candidates[i], combination, i)
            combination.pop() 