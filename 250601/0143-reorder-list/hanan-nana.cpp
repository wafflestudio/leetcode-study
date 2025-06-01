#include <vector>
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
            while (head != nullptr) {
                list.push_back(head);
                head = head->next;
            }
    
            for (int i = 0; i < list.size()/2; i++) {
                if (i == list.size()/2-1) {
                    list[i]->next = list[list.size()-1-i];
                    if (list.size() % 2 == 1) {
                        list[list.size()-1-i]->next = list[i+1];
                        list[i+1]->next = nullptr;
                    }
                    else
                        list[list.size()-1-i]->next = nullptr;
                } else {
                    list[i]->next = list[list.size()-1-i];
                    list[list.size()-1-i]->next = list[i+1];
                }
            }
        }
    };