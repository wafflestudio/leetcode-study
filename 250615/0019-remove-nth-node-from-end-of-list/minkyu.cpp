#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        vector<ListNode*> arr;
        ListNode* now = head;
        while (now != nullptr) {
            arr.push_back(now);
            now = now->next;
        }
        int target = arr.size() - n;
        if (target == 0) return head->next;

        if (n == 1) arr[target-1]->next = nullptr;
        else arr[target-1]->next = arr[target+1];

        return head;
    }
};
