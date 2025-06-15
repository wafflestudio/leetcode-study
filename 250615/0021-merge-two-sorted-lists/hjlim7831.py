# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None:
            return list2
        if list2 == None:
            return list1
        
        now1, now2 = list1, list2

        if now1.val < now2.val:
            answer = now1
            now1 = now1.next
        else:
            answer = now2
            now2 = now2.next
        
        answer_now = answer

        while now1 != None and now2 != None:
            if now1.val < now2.val:
                answer_now.next = now1
                now1 = now1.next
            else:
                answer_now.next = now2
                now2 = now2.next
            answer_now = answer_now.next
        while now1 != None:
            answer_now.next = now1
            now1 = now1.next
            answer_now = answer_now.next
        
        while now2 != None:
            answer_now.next = now2
            now2 = now2.next
            answer_now = answer_now.next


        return answer