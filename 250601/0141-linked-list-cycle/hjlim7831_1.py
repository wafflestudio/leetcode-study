# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        answer = False
        visited = set()
        visited.add(head)
        now = head
        while now != None:
            if now.next in visited:
                answer = True
                break
            visited.add(now.next)
            now = now.next
        return answer