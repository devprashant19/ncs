class Solution {
    vector<int>ans;
    void dfs(TreeNode* root){
        if(root==NULL)return;
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};