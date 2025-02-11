class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        for (int r = 0; r < grid.size(); r++) {
            if (r % 2 == 0) {
                for (int c = 0; c < grid[0].size(); c+=2)
                    if (c % 2 == 0) ans.push_back(grid[r][c]); // we can do c+=2 also
            } else {
                for (int c = grid[0].size() - 1; c >= 0; c--)
                    if (c % 2 == 1) ans.push_back(grid[r][c]); // we could find the start
            }
        }
        return ans;
    }
};