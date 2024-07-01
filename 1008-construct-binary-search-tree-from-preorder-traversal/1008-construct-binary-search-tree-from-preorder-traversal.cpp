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
    TreeNode* link(TreeNode* root,int value)
    {
        if(!root)
        {
            TreeNode * node=new TreeNode(value);
            return node;
        }
        
        if(root->val>=value)
        {
           root->left=link(root->left,value); 
        }
        else
        {
            root->right=link(root->right,value);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root=new TreeNode(preorder[0]);
        int size=preorder.size();
        if(size==1)
            return root;
        
        for(int i=1;i<size;i++)
        {
            root=link(root,preorder[i]);
        }
        return root;
    }
};