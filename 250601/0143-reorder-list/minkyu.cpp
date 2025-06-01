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


        int mid = (list.size()) / 2;
        for (int i = 0; i < mid; i++) {
            list[i]->next = list[list.size() - i - 1];
        }

        for (int i = mid + 1; i < list.size(); i++) {
            list[i]->next = list[list.size() - i];
        }

        list[mid]->next = nullptr;
    }
};
