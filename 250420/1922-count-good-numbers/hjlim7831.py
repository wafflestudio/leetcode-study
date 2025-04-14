class Solution:
    def countGoodNumbers(self, n: int) -> int:
        DIV = 1_000_000_007
        answer = pow(20, n // 2, DIV)
        if n % 2 != 0:
            answer = (answer * 5) % DIV

        return answer
