#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (!min_heap.empty() && min_heap.top() < num) min_heap.push(num);
        else max_heap.push(num);

        while (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        while (min_heap.size() + 1 < max_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double findMedian() {
        if (min_heap.size() == max_heap.size()) return (min_heap.top() + max_heap.top()) / 2.0;
        else return max_heap.top();
    }
};


int main() {
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
}