from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n  = len(matrix)
        new_matrix = [[] for _ in range(n)]

        for i in range(n):
            for index, j in enumerate(matrix[n - i - 1]):
                new_matrix[index].append(j)

        while len(matrix) > 0:
            matrix.pop()

        for row in new_matrix:
            matrix.append(row)

