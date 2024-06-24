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
        vector<vector<int>>res;
        if(!root)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()&&q.front())
        {   vector<int> temp;
            while(q.front())
            {
               TreeNode* elm =q.front();
                q.pop();
                if(elm->left)
                {
                    q.push(elm->left);
                }
                if(elm->right)
                {
                    q.push(elm->right);
                }
                temp.push_back(elm->val);
            }
           q.push(NULL);
           res.push_back(temp);
           temp.clear();
            q.pop();
        }
        return res;
    }
};