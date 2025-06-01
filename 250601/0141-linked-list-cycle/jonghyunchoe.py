# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        nodes = []
        if head == None:
            return False
        
        while head.next != None and head not in nodes:
            nodes.append(head)
            head = head.next 
        if head in nodes:
            return True
        else:
            return False
