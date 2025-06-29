from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()

        answer = []

        def track(total: int, combinations: List[int], start: int):
            if total == target:
                answer.append(combinations.copy())
                return
            if total > target:
                return

            for i in range(start, len(candidates)):
                combinations.append(candidates[i])
                track(total + candidates[i], combinations, i)
                combinations.pop()

        track(0, [], 0)

        return answer