import heapq
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        list_map = {}
        list_heap = []
        for idx, item in enumerate(lists):
            if not item:
                continue
            list_map[idx] = item
            heapq.heappush(list_heap, (item.val, idx))

        answer = None
        pos = None

        while list_heap:
            val, idx = heapq.heappop(list_heap)
            curr = list_map[idx]
            if not answer:
                answer = list_map[idx]
                pos = answer
            else:
                pos.next = curr
                pos = pos.next

            if curr.next:
                list_map[idx] = curr.next
                heapq.heappush(list_heap, (curr.next.val, idx))
                curr.next = None
        
        return answer