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
    void rightview(TreeNode* root,vector<int>&res,int level)
    {
        if(root==NULL)
            return;
        if(res.size()<level)
        {
            res.push_back(root->val);
            rightview(root->right,res,level+1);
        }
        
         rightview(root->right,res,level+1);
         rightview(root->left,res,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
       if(root==NULL)
           return res;
     
        if(root->left==NULL&&root->right==NULL)
        {    res.push_back(root->val);
          return res;}
    
        int level=1;
        rightview(root,res,level);
        return res;
    }
};