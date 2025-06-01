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
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        ListNode* temp = head;
        while (temp != nullptr) {
            list.push_back(temp);
            temp = temp->next;
        }

        for (int i = 0; i < list.size(); i++) {
            list[i]->next = list[list.size() - i - 1];
        }
        int mid = (list.size() + 1) / 2;
        list[mid]->next = nullptr;
    }
};
