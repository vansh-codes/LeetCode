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
public:
    pair<int, int>
    diameterOptimized(TreeNode* root) // tc O(n), space c: O(height)
    {
        // base case
        // pair first part = diameter, second part = height
        if (root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameterOptimized(root->left);
        pair<int, int> right = diameterOptimized(root->right);

        int leftTree = left.first;
        int rightTree = right.first;
        int combo = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(leftTree, max(rightTree, combo));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOptimized(root).first - 1;
    }
};