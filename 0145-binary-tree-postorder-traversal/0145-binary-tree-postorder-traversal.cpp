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
    void postorder(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        postorder(root->left,res);
     
        postorder(root->right,res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> res;
        if(root==NULL)
            return res;
        if(root->left==NULL&&root->right==NULL)
        { res.push_back(root->val);
         return res;}
        
        postorder(root,res);
        return res; 
    }
};