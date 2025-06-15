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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* head;
        if (list1->val > list2->val) {
            head = list2;
            list2 = list2->next;
        } else {
            head = list1;
            list1 = list1->next;
        }

        ListNode* now = head;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                now->next = list2;
                break;
            } else if (list2 == nullptr) {
                now->next = list1;
                break;
            } else {
                if (list1->val < list2->val) {
                    ListNode* old_list1 = list1;
                    list1 = list1->next;
                    now->next = old_list1;
                    now = old_list1;
                } else {
                    ListNode* old_list2 = list2;
                    list2 = list2->next;
                    now->next = old_list2;
                    now = old_list2;
                }
            }
        }
        return head;
    }
};
