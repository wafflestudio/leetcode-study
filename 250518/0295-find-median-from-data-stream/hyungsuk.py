import heapq


# youngin님 코드 참고
class MedianFinder(object):
    def __init__(self):
        self.maxHeap = []  # small half
        self.minHeap = []  # large half

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        heapq.heappush(self.maxHeap, -num)
        heapq.heappush(self.minHeap, -heapq.heappop(self.maxHeap))

        # 같게
        if len(self.maxHeap) < len(self.minHeap):
            heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.maxHeap) > len(self.minHeap):  # 홀수
            return -self.maxHeap[0]
        else:  # 짝수
            return (-self.maxHeap[0] + self.minHeap[0]) / 2.0  # Using 2.0 to ensure float division


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
