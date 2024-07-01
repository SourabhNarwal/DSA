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
    bool validity(TreeNode* root,long long int ub,long long int lb)
    {
        if(!root)
            return true;
       
        if(root->val>=ub||root->val<=lb)
            return false;
        
        if(validity(root->left,root->val,lb))
        {
           return validity(root->right,ub,root->val); 
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int ub =10000000000;
         long long int lb =-10000000000;
       return validity(root,ub,lb) ;
    }
};