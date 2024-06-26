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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>res;
        if(!root)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        while(!q.empty()&&q.front())
        {
            while(q.front())
            { 
              auto elm=q.front();
              q.pop();
              if(elm->left)
              {q.push(elm->left);}
              if(elm->right)
              {q.push(elm->right);}
             temp.push_back(elm->val);
            }
            q.push(NULL);q.pop();
            res.push_back(temp);temp.clear();
        }
        
        for(int i=0;i<res.size();i++)
        {
            if(i%2!=0)
            {
                temp=res[i];
                reverse(temp.begin(), temp.end());
                res[i]=temp;temp.clear();
            }
        }
        return res;
    }
};