class Solution:

    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        subsets = [[n] for n in nums]
        for idx, numi in enumerate(nums):
            for jdx, numj in enumerate(nums[:idx]):
                stack = subsets[jdx]
                if numi % numj == 0 and len(stack) + 1 > len(subsets[idx]):
                    subsets[idx] = stack + [numi]
        
        answer = []
        for subset in subsets:
            if len(subset) > len(answer):
                answer = subset
        
        return answer
        





            

            




