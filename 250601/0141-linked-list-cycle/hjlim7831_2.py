# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        answer = False
        turtle, rabbit = head, head
        while True:
            if turtle == None or turtle.next == None:
                break
            turtle = turtle.next.next
            rabbit = rabbit.next
            if turtle == rabbit:
                answer = True
                break
        return answer