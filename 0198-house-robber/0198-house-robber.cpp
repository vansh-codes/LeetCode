class Solution {
// private:
    // using memoization
    /* int maxRob(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int pick = nums[ind] + maxRob(ind-2, nums, dp);
        int notPick = maxRob(ind-1, nums, dp);

        return dp[ind] = max(pick, notPick);

    } */

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return maxRob(n-1, nums, dp);    // use for memoization code

        // using tabulation
        /* dp[0] = nums[0];
        int pick, notPick;
        for(int i=1;i<n;i++){
            pick = nums[i];
            if(i>1) pick += dp[i-2];
            notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[n-1]; */

        // using tabulation - space optimized
        int prev1 = nums[0];
        int prev2 = 0;
        int pick, notPick;
        for(int i=1;i<n;i++){
            pick = nums[i];
            if(i>1) pick += prev2;
            notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};