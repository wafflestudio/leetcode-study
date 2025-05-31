from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited = set()
        pointer = head
        while pointer:
            visited.add(pointer)
            if pointer.next in visited:
                return True
            pointer = pointer.next
        return False