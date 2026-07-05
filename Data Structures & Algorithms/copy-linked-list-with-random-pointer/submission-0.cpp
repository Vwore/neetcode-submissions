/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        vector<Node*> lt;
        map<Node*, int> mp;
        auto curr = head;
        int i = 0;
        while (curr) {
            mp[curr] = i;
            curr = curr->next;
            i++;
        }
        Node* head2 = new Node(-1);
        curr = head;
        auto curr2 = head2;
        while (curr) {
            curr2->next = new Node(curr->val);
            curr2 = curr2->next;
            lt.push_back(curr2);
            curr = curr->next;
        }

        curr = head;
        curr2 = head2->next;
        while (curr && curr2) {
            if (curr->random != nullptr) {
                int index = mp[curr->random];
                // cout<<index;
                // cout<<curr->random->val<<" "<<lt[index]->val<<endl;

                curr2->random = lt[index];
            }
            else curr2->random =nullptr;
            curr2 = curr2->next;
            curr = curr->next;
        }
        return head2->next;
    }
};
