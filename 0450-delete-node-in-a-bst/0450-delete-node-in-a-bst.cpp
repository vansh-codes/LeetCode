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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else{
            if(!root->left && !root->right){
                delete(root);
                return NULL;
            } else if(!root->left || !root->right){
                TreeNode* tmp = root->left ? root->left : root->right;
                delete(root);
                return tmp;
            } else if(root->left && root->right){
                TreeNode* tmp = root->right;
                while(tmp->left) tmp = tmp->left;
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            }
        }
        return root;
    }
};