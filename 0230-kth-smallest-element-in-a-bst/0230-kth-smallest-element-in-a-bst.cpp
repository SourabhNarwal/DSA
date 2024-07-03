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
    void inorder(TreeNode* root,int k,int &x,int &ans)
    {
        if(!root)
            return;
        inorder(root->left,k,x,ans);
        x=x+1;
        if(x==k)
        {
            ans=root->val;
        }
        if(x>k)
            return;
        inorder(root->right,k,x,ans);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int x=0;
        inorder(root,k,x,ans);
        return ans;
    }
};