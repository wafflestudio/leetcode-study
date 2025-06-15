# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(-1)
        curr = head

        while list1 or list2:
            if list1 is None:
                curr.next = list2
                curr = list2
                list2 = list2.next
            elif list2 is None:
                curr.next = list1
                curr = list1
                list1 = list1.next
            elif list1.val <= list2.val:
                curr.next = list1
                curr = list1
                list1 = list1.next
            else:
                curr.next = list2
                curr = list2
                list2 = list2.next

        return head.next

