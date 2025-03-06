class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>v(n*m+1,0);
        vector<int>ans;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                v[grid[i-1][j-1]]+=1;
                if(v[grid[i-1][j-1]]==2){
                    ans.push_back(grid[i-1][j-1]);
                }
            }
        }
        for(int i=1;i<=(n*m);i++){
            if(v[i]==0){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};