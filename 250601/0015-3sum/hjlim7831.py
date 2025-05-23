from collections import defaultdict

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        num_cnt = defaultdict(int)
        for n in nums:
            num_cnt[n] += 1
        answer_set = set()
        for i in num_cnt.keys():
            for j in num_cnt.keys():
                if -i-j in num_cnt.keys():
                    triplets = defaultdict(int)
                    triplets[i] += 1
                    triplets[j] += 1
                    triplets[-i-j] += 1
                    for t in triplets.keys():
                        if num_cnt[t] < triplets[t]:
                            break
                    else:
                        tmp = [i, j, -i-j]
                        tmp.sort()
                        answer_set.add(tuple(tmp))
        answer = []
        for a in answer_set:
            answer.append(list(a))

        return answer
