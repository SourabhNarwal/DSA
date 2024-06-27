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
    TreeNode * tree(vector<int>&preorder,int preidx,int size, vector<int>&inorder,int start,int end)
    {   if(start>end)
        {return NULL;}
        if(start==end)
        {
            return new TreeNode(inorder[start]);
        }
       
        int x=-1;
        for(int i=preidx;i<size;i++)
        {
           int elm=preorder[i];
            for(int j=start;j<=end;j++)
            {
                if(elm==inorder[j])
                {
                    x=j;
                    preidx=i+1;
                    break;
                }
            }
            if(x!= -1)
            {break;}
        }
        
        TreeNode * node=new TreeNode(inorder[x]);
        
        node->left=tree(preorder,preidx,size,inorder,start,x-1);
        node->right=tree(preorder,preidx,size,inorder,x+1,end);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
        TreeNode * root=tree(preorder,0,size,inorder,0,size-1);
        return root;
    }
};