/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// time complexity O(N+M)


class Solution {
    struct Compare {
        bool operator()(ListNode* n1, ListNode* n2) {
            return n1->val > n2-> val;
        }
    };
  
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto& n : lists) {
            if (n) pq.push(n);
        }
  
        ListNode dummy(0);
        ListNode* last = &dummy;
        while (!pq.empty()) {
            last->next = pq.top();
            last = pq.top();
            pq.pop();
            if (last->next) pq.push(last->next);
        }
        
        return dummy.next;
    }
  };