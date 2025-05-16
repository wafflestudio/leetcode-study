import heapq


class MedianFinder:

    def __init__(self):
        self.max_heap = []
        self.min_heap = []
        

    def addNum(self, num: int) -> None:
        if not self.max_heap or num <= self.max_heap[0][1]:
            heapq.heappush(self.max_heap, (-num, num))
        else:
            heapq.heappush(self.min_heap, (num, num))
        
        if len(self.max_heap) > len(self.min_heap) + 1:
            val = self.max_heap[0][1]
            heapq.heappush(self.min_heap, (val, val))
            heapq.heappop(self.max_heap)
        elif len(self.min_heap) > len(self.max_heap):
            val = self.min_heap[0][1]
            heapq.heappush(self.max_heap, (-val, val))
            heapq.heappop(self.min_heap)

    def findMedian(self) -> float:
        if len(self.min_heap) == len(self.max_heap):
            return (self.min_heap[0][1] + self.max_heap[0][1]) / 2
        else:
            return self.max_heap[0][1]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()