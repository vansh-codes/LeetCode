class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        long long negatives = 0, res = 0, n = a.size(), mini = 1000000;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                res += abs(a[i][j]);
                if (a[i][j] < 0)
                    negatives++;
                mini = mini < abs(a[i][j])? mini: abs(a[i][j]);
            }
        if (negatives % 2 == 0)
            return res;
        else 
            return res - 2*mini;
    }
};