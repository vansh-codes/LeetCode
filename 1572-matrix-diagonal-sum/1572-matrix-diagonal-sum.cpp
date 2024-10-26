class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int r = mat.size();
        for(int i=0;i<r;i++){
            sum += mat[i][i] + mat[r-i-1][i];
        }
        if(r%2!=0) sum -= mat[r/2][r/2];
        return sum;
    }
};