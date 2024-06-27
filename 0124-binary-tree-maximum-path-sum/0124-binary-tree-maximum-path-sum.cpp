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
    int maxsum(TreeNode * root,int &maxi)
    {
        if(!root)
            return NULL;
        int ls=max(0,maxsum(root->left,maxi));
        int rs=max(0,maxsum(root->right,maxi));
    
        maxi=max(maxi,ls+root->val+rs);
        
        return  root->val+ max(ls,rs);
    
    }
public:
    int maxPathSum(TreeNode* root) {
       
        int maxi=INT_MIN;
        maxsum(root,maxi);
        return maxi;
    }
};