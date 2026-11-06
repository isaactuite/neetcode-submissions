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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (!head || !head->next) return nullptr;
        int length =0;
        ListNode* curr1 = head;
        
        while (curr1){
            length++;
            curr1 = curr1->next;
        }

        int pos = length-n+1;

        ListNode* curr2 = head;
        ListNode* prev = head;
        int count = 0;
        while(curr2){
            count++;
            ListNode* next2 = curr2->next;
            

            if (count == pos){
                if (prev == curr2){
                    head = next2;
                    delete curr2;
                    break;
                }

                prev->next = next2;
                delete curr2;
                break;
            }

            prev = curr2;
            curr2 = next2;
        }
        return head;
    }
};
