
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
            ListNode* dummy = new ListNode();
            ListNode* cur = dummy;
    
            while (list1 != nullptr || list2 != nullptr) {
                if (list1 == nullptr) {
                    cur->next = list2;
                    cur = cur->next;
                    list2 = list2->next;
                } else if (list2 == nullptr) {
                    cur->next = list1;
                    cur = cur->next;
                    list1 = list1->next;
                } else if (list1->val > list2->val) {
                    cur->next = list2;
                    cur = cur->next;
                    list2 = list2->next;
                } else {
                    cur->next = list1;
                    cur = cur->next;
                    list1 = list1->next;
                }
            }
            ListNode* begin = dummy->next;
            delete dummy;
            return begin;
        }
    };