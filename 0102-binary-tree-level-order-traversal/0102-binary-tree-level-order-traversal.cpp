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
       
        
        while(!q.empty())
        {   vector<int> temp;
            int size=q.size();
            int i=0;
            while(i<size)
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
                i++;
                temp.push_back(elm->val);
            }
           
           res.push_back(temp);
           temp.clear();
    
        }
        return res;
    }
};