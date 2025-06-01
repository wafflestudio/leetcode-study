#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while (head != NULL) {
            if (head->val == -999999) return true;
            head->val = -999999;
            head = head->next;
        }
        return false;
    }
};