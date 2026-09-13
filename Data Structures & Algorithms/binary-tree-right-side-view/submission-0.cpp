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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<pair<TreeNode*,int>> q;
        int currentLevel=-1;
        q.push({root,0});
        vector<int> answer;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            auto node = temp.first;
            auto level = temp.second;
            if(currentLevel < level)
            {
                answer.push_back(node->val);
                currentLevel = level;
            }

            if(node->right)
            {
                q.push({node->right,level+1});
            }

            if(node->left)
            {
                q.push({node->left,level+1});
            }


        }
        return answer;
    }
};
