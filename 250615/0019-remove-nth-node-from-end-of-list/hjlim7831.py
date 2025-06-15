# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        nodes = []
        now = head
        while now:
            nodes.append(now)
            now = now.next
        
        if len(nodes) == 1:
            return None

        if n == 1:
            nodes[-2].next = None
        else:
            nodes[-n-1].next = nodes[-n+1]        

        return head