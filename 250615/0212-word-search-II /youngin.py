from collections import defaultdict
from typing import List, Optional


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        head = TrieNode("Skip")
        for word in words:
            node = head
            for c in word:
                if node.next[c].data == "None":
                    node.next[c] = TrieNode("Skip")
                node = node.next[c]
            node.data = word

        result_words = set()

        def dfs(i, j, p: TrieNode):
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] == "":
                return
            ch = board[i][j]
            p = p.next[ch]
            if p.data == "None":
                return

            if p.data != "Skip":
                result_words.add(p.data)

            board[i][j] = ""
            dfs(i + 1, j, p)
            dfs(i - 1, j, p)
            dfs(i, j + 1, p)
            dfs(i, j - 1, p)
            board[i][j] = ch


        for i in range(len(board)):
            for j in range(len(board[0])):
                dfs(i, j, head)
        return list(result_words)

class TrieNode:
    def __init__(self, data: str = "None"):
        self.data = data
        self.next = defaultdict(TrieNode)