class Solution(object):
    def maximumScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(nums)

        def get_prime_score(num):
            score = 0
            d = 2
            while d * d <= num:
                if num % d == 0:
                    score += 1
                    while num % d == 0:
                        num //= d
                d += 1
            if num != 1:
                score += 1
            return score

        prime_scores = [get_prime_score(num) for num in nums]

        left = [-1] * n  # left boundary
        right = [n] * n  # right boundary

        # lefts
        stack = []
        for i in range(n):
            while stack and prime_scores[stack[-1]] < prime_scores[i]:
                stack.pop()
            if stack:
                left[i] = stack[-1]
            stack.append(i)

        # rights
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and prime_scores[stack[-1]] <= prime_scores[i]:
                stack.pop()
            if stack:
                right[i] = stack[-1]
            stack.append(i)

        possible_contributions = []
        for i in range(n):
            count = (i - left[i]) * (right[i] - i)
            possible_contributions.append((nums[i], count))

        possible_contributions.sort(key=lambda x: -x[0])

        result = 1
        for num, count in possible_contributions:
            c = min(k, count)
            result = (result * pow(num, c, MOD)) % MOD
            k -= c
            if k == 0:
                break

        return result
