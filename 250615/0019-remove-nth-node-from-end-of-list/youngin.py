# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        l = []
        curr = ListNode(0, head)
        while curr.next is not None:
            curr = curr.next
            l.append(curr)

        if len(l) == 1: return None

        if n == len(l):
            head = l[1]
        elif n == 1:
            l[-2].next = None
        else:
            prev_node = l[len(l) - n - 1]
            next_node = l[len(l) - n + 1]
            prev_node.next = next_node

        return head