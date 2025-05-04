# Definition for singly-linked list.
from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) < 1:
            return None
        while(len(lists) > 1):
            next = []
            for i in range(0, len(lists), 2):
                first = lists[i]
                if i + 1 >= len(lists):
                    second = None
                else:
                    second = lists[i + 1]
                
                node = ListNode()
                root = node

                while first and second:
                    if first.val > second.val:
                        node.next = second
                        second = second.next
                    else:
                        node.next = first
                        first = first.next
                    node = node.next
                
                if first:
                    node.next = first
                else:
                    node.next = second
                next.append(root.next)
            lists = next
        
        return lists[0]

first = ListNode(val =  1, next = ListNode(4, ListNode(5)))
second = ListNode(val =  1, next = ListNode(3, ListNode(4)))
third = ListNode(val =  2, next = ListNode(6))

print(Solution().mergeKLists([first, second, third]))
print(Solution().mergeKLists([]))