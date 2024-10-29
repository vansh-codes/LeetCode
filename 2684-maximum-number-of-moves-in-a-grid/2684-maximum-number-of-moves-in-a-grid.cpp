class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> cache(r, vector<int>(c, -1));
        vector<pair<int, int>> directions = {{0, 1}, {1, 1}, {-1, 1}};

        function<int(int, int)> dp = [&](int i, int j) {
            if (cache[i][j] != -1)
                return cache[i][j];

            int maxMoves = 0;
            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < r && nj < c && grid[ni][nj] > grid[i][j]) {
                    maxMoves = max(maxMoves, 1 + dp(ni, nj));
                }
            }
            return cache[i][j] = maxMoves;
        };

        int result = 0;
        for (int i = 0; i < r; i++) {
            result = max(result, dp(i, 0));
        }
        return result;
    }
};