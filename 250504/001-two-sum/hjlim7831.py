class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = {}
        for n in nums:
            if n not in nums_dict:
                nums_dict[n] = 1
            else:
                nums_dict[n] += 1
        answer = []
        for n in nums:
            op = target - n
            if n == op and nums_dict[n] == 1:
                continue
            if op in nums_dict:
                answer = [n, op]
                break
        
        if answer[0] == answer[1]:
            all_index = list(filter(lambda x: nums[x] == answer[0], range(len(nums))))
            return all_index[:2]

        return [nums.index(n) for n in answer]