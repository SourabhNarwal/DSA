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
    TreeNode* rightmost(TreeNode* root)
    {   if(!root)
           return root;
     
        if(!root->left && !root->right)
             return root;
        return rightmost(root->right);
        
    }
    TreeNode* flat(TreeNode* root)
    {
        if(!root)
         return NULL ;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode *temp1=rightmost(root->left);
        if(temp1)
        {
            temp1->right=root->right;
            root->right=root->left;
            root->left=NULL;
            return root;
        }
        return root;
    }
public:
    void flatten(TreeNode* root) {
   
        if(!root||(!root->left&& !root->right))
            return;
        
        root->left=flat(root->left);
        root->right=flat(root->right);
        TreeNode *temp1=rightmost(root->left);
        if(temp1)
        {
            temp1->right=root->right;
            root->right=root->left;
            root->left=NULL;
            
        }
    }
};