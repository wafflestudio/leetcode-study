class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        answer = nums[0]
        add = nums[0]

        for n in nums[1:]:
            add = max(n, add + n)
            answer = max(answer, add)
        
        return answer


        