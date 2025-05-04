# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        start = None
        while any(lists):
            lists = [i for i in lists if i]
            if not lists:
                break

            min_head_val_idx = 0
            for i in range(1, len(lists)):
                if lists[i].val < lists[min_head_val_idx].val:
                    min_head_val_idx = i

            if not start:
                start = lists[min_head_val_idx]
                current = start
            else:
                current.next = lists[min_head_val_idx]
                current = current.next

            lists[min_head_val_idx] = lists[min_head_val_idx].next

        return start
