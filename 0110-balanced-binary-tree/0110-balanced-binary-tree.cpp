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
    int findheight(TreeNode* root,bool &ans)
    {
        if(!root)
            return 0;
        int lh,rh;
        lh=findheight(root->left,ans);
        rh=findheight(root->right,ans);
        if(abs(lh-rh)>1)
        { ans=false;
        }
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        int h=findheight(root,ans);
        return ans;
    }
};