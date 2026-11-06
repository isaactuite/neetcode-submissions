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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* one = head;
        if (!head) return false;
        ListNode* two = head->next;
        
        while (one->next!=nullptr && two->next){
            if (one == two){
                return true;
            }

            if (two->next->next == nullptr){
                return false;
            }

            two = two->next->next;
            one = one->next;
        }

        return false;
    }
};
