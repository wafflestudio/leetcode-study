#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    private:
        unordered_set<ListNode*> history;
    
    public:
        bool hasCycle(ListNode *head) {
            if (head == nullptr) return false;
            while (head->next != nullptr) {
                if (history.find(head) != history.end()) return true;
                history.insert(head);
                head = head->next;
            }
            return false;
        }
    };