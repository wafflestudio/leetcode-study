class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        for i in range(n // 2):
            start = i
            end = n - 1 - i
            for j in range(start, end):
                diff = j - start

                tmp = matrix[start][j]
                matrix[start][j] = matrix[end - diff][start]
                matrix[end - diff][start] = matrix[end][end - diff]
                matrix[end][end - diff] = matrix[j][end]
                matrix[j][end] = tmp
