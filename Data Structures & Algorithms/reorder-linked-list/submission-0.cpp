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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* dummy = slow;
        while (slow->next !=nullptr && fast->next){
            dummy = slow;
            if (fast->next->next == nullptr){
                fast=fast->next;
            } else{
                fast=fast->next->next;
            }
            
            slow = slow->next;
                        
        }

        dummy->next = nullptr;

        ListNode* prev = slow;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        while (curr->next){
            ListNode* next = curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }

        curr->next = prev;

        ListNode* curr2 = head;

        while (curr){
            ListNode* next2 = curr2->next;
            ListNode* next = curr->next;

            curr2->next = curr;
            if (!next2) break;
            curr->next = next2;

            curr = next;
            curr2 = next2;
        }

    }
};
