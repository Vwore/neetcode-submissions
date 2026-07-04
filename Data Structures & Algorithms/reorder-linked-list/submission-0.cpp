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
        vector<ListNode*> lt;
        auto curr= head;
        while(curr)
        {
            lt.push_back(curr);
            curr=curr->next;
        }
        int n= lt.size();

        if(n==1) return;
        int l=1,r=n-1;
        curr=head;
        // cout<<curr->val;
        while(l<=r)
        {
            curr->next=lt[r--];
            curr=curr->next;
            if(l==(r+1)) {
                curr->next = nullptr;
                break;
            }
            // cout<<curr->val<<endl;
            curr->next=lt[l++];
            curr=curr->next;
            curr->next=nullptr;
            // cout<<curr->val;
            // break;
        }
            }
};
