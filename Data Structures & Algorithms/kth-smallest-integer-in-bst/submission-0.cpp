/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int kValue,currentNode,answer;
    bool kReached;

    void dfs(TreeNode* node)
    {
        if(node == nullptr) return;
        dfs(node->left);
        if(kReached) return;
        currentNode++;
        if(currentNode == kValue){
            kReached=true;
            answer=node->val;
            return;
        }
        
        dfs(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
       kValue=k;
       currentNode=0;
        kReached =false;
        dfs(root);
        return answer;
    }
};
