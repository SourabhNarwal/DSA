/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool path(TreeNode * root,deque<TreeNode *>&nodepath,TreeNode* node)
    {
        if(!root)
            return false;
        if(root==node)
        {
            nodepath.push_front(root);
            return true;
        }
        
        nodepath.push_front(root);
        bool found=false;
        found=path(root->left,nodepath,node);
        if(found)
            return true;
        found=path(root->right,nodepath,node);
             if(found)
            return true;
        nodepath.pop_front();
        return false;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode *>ppath;
        deque<TreeNode *>qpath;
        path(root,ppath,p);
        path(root,qpath,q);
        
        while(1)
        {
            TreeNode* node=ppath.front();
            ppath.pop_front();
            
            deque<TreeNode*>::iterator itr;
            itr = find(qpath.begin(), qpath.end(), node);
            if(itr != qpath.end())
            {
                return node;
            }
            
        }
        
    }
};