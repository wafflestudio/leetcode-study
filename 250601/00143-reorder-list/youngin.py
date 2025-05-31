# Definition for singly-linked list.
from collections import deque
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None:
            return
        dq = deque()
        pointer = head
        while pointer.next:
            dq.append(pointer.next)
            pointer = pointer.next

        c = head
        while True:
            if len(dq) <= 0:
                break
            c.next = dq.pop()
            c = c.next
            if len(dq) <= 0:
                break
            c.next = dq.popleft()
            c = c.next
        c.next = None
