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
class BSTIterator {
    stack<TreeNode*> tree;
    void pushnodes(TreeNode * root, stack<TreeNode*> &tree)
    {
        while(root)
        {
            tree.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushnodes(root,tree);
    }
    
    int next() {
        
        
            auto node=tree.top();
            
            tree.pop();
            pushnodes(node->right,tree);
            return node->val;
        
        
    }
    
    bool hasNext() {
        if(tree.empty())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */