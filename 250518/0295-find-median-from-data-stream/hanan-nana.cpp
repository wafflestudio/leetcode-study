#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
    private:
        priority_queue<int, vector<int>, greater<int>> rightQ;
        priority_queue<int> leftQ;
        int count;
    
    public:
        MedianFinder() {
            count = 0;
        }
        
        void addNum(int num) {
            if (count % 2 == 0) {
                leftQ.push(num);
                rightQ.push(leftQ.top());
                leftQ.pop();
            } else {
                rightQ.push(num);
                leftQ.push(rightQ.top());
                rightQ.pop();
            }
            count++;
        }
        
        double findMedian() {
            if (count % 2 == 0) {
                return (rightQ.top() + leftQ.top()) / 2.0;
            } else {
                return rightQ.top();
            }
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */