/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    vector<int> res;

public:
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }

        if (depth == res.size()) {
            res.push_back(node->val);
        } else {
            res[depth] = max(res[depth], node->val);
        }

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};