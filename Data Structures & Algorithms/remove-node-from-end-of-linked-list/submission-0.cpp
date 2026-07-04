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
        int count=0;
        auto curr= head;
        while(curr)
        {
            count++;
            curr=curr->next;
        }
        int elementToRemove = count-n+1;
        if(count == 1 ) return nullptr;
        if(elementToRemove ==1) return head->next;
        int newCount =0;
        curr=head;
        while(curr)
        {
            newCount++;
            if(newCount+1==elementToRemove)
            {
                curr->next=curr->next->next;
            }
            curr=curr->next;
        }
        return head;

    }
};
