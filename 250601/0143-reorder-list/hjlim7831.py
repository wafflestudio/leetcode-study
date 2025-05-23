# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        nodes = []
        now = head
        while now != None:
            nodes.append(now)
            now = now.next
            nodes[-1].next = None
        
        idxs = [1, len(nodes) - 1]
        turn = 0
        now = head
        while idxs[0] <= idxs[1]:
            if turn % 2 == 0:
                pos = idxs[1]
                idxs[1] -= 1
            else:
                pos = idxs[0]
                idxs[0] += 1
            now.next = nodes[pos]
            now = now.next
            turn += 1




        