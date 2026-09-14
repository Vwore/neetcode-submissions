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

    int answer;
    int sol(TreeNode* node)
    {
        if(node==nullptr) return -1;
        if(node->left == nullptr && node->right == nullptr) return 0;
        int leftLevel = sol(node->left);
        int rightLevel = sol(node->right);
        answer = max(answer, leftLevel+rightLevel+2);
        return max(leftLevel+1,rightLevel+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        answer =0;
        sol(root);
        return answer;
    }
};
