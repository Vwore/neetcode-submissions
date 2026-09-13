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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        vector<vector<int>> ans;
        while(!q.empty())
        {
            auto x = q.front();
            if(ans.size()<x.second+1)
            {
                ans.push_back({x.first->val});
            }
            else{
                ans[x.second].push_back(x.first->val);
            }
            q.pop();
            // cout<<x->val<<" ";
            if(x.first->left)
            {
                q.push({x.first->left,x.second+1});
            }

            if(x.first->right)
            {
                q.push({x.first->right,x.second+1});
            }

        }
        return ans;
    }
};
