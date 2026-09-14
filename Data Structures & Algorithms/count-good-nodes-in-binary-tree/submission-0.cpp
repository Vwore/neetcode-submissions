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

    int sol(TreeNode* node,int maxVal) 
    {
        int ans=0;
        if(maxVal<=node->val) 
        {
            ans++;
            maxVal=node->val;
        }
        if(node->left !=nullptr) 
        {
            ans+= sol(node->left,maxVal);
        }
        if(node->right !=nullptr) 
        {
            ans+= sol(node->right,maxVal);
        }

        return ans;

    }
    int goodNodes(TreeNode* root) {
        return sol(root,-101);
    }
};
