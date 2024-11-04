class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;

        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
        /* int grid[m][n];
        for(int i=0,j=0;j<n;j++)
          {
            grid[i][j]=1;
          }
        for(int j=0,i=0;i<m;i++)
          {
            grid[i][j]=1;
          }
        
        for(int i=1;i<m;i++)
          {
            for(int j=1;j<n;j++)
              {
                grid[i][j]=grid[i-1][j] + grid[i][j-1];
              }
          }

        return grid[m-1][n-1];
    } */
};