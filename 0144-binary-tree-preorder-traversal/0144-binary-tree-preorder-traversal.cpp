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
private:
    void helper(TreeNode* root, vector<int> &res){
        if(root==NULL) return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
        return;
    }
public:
    // iterative
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            res.push_back(root->val);
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }
        return res;
    }

    // recursive
    /* vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    } */
};