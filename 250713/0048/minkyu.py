import math
from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        two_c = n - 1
        x_max = math.ceil(n / 2)
        y_max = math.ceil((n - 1) / 2)
        for x in range(x_max):
            for y in range(y_max):
                old_value = matrix[x][y]
                old_x = x
                old_y = y
                for _ in range(4):
                    """
                    Let c be the coorinate of the center of the matrix.
                    e.g. c = 1 when n = 3, c = 1.5 when n = 4
                    original coordinate: x + yi
                    after translation: (x + yi) - (c + ci) = (x - c) + (y - c)i
                    after rotation: ((x - c) + (y - c)i) * -i = (y - c) + (c - x)i
                    after recovery of translation: (y - c) + (c - x)i + (c + ci) = y + (2c - x)i
                    """
                    new_x = old_y
                    new_y = two_c - old_x
                    temp = matrix[new_x][new_y]
                    matrix[new_x][new_y] = old_value
                    old_value = temp
                    old_x = new_x
                    old_y = new_y
