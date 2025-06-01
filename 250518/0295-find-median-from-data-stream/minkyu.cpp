#include <bits/stdc++.h>
using namespace std;


class MedianFinder {
private:
    vector<int> arr;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        for (auto it = arr.begin(); it != arr.end(); it++) {
            if (*it > num) {
                arr.insert(it, num);
                return;
            }
        }
        arr.push_back(num);
    }
    
    double findMedian() {
        if (arr.size() % 2 == 1) {
            return arr[arr.size() / 2];
        } else {
            return (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2.0;
        }
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