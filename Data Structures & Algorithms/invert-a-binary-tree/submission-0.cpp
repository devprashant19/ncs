class Solution {
    void dfs(TreeNode* root){
        if(root==NULL)return;
        swap(root->left,root->right);
        if(root->left)dfs(root->left);
        if(root->right)dfs(root->right);
        return;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
