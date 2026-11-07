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
    struct compareVal{
        bool operator()(const ListNode* a, const ListNode* b) const{
            return a->val > b->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, compareVal> pq;
        

        for (auto& head : lists){
            while (head){
                pq.push(head);
                head = head->next;
            }
        }
        if (pq.empty()) return lists[0];
        ListNode* head = pq.top();
        ListNode* prev = head;

        pq.pop();
        while (!pq.empty()){
            ListNode* top = pq.top();
            prev->next = top;
            prev = top;
            pq.pop();
        }

        return head;
    }
};
