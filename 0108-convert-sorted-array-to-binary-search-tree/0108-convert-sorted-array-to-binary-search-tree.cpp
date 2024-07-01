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
    TreeNode * bst(vector<int>nums,TreeNode* root,int start,int end)
    {   if(start>end)
        return NULL;
        if(start==end)
        {
          TreeNode* node=new TreeNode(nums[start]);
            return node;
        }
        int mid=start +((end-start)/2);
        TreeNode* node=new TreeNode(nums[mid]);
        
        node->left=bst(nums,root,start,mid-1);
        node->right=bst(nums,root,mid+1,end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size=nums.size();
        int mid=size/2;
        
        TreeNode *root=new TreeNode(nums[mid]);
        if(size==1)
            return root;
        root->left=bst(nums,root,0,mid-1);
        root->right=bst(nums,root,mid+1,size-1);
        return root;
        
    }
};