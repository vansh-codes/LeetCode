class Solution {
private:
    bool canYouReach(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx == nums.size() - 1)
            return true;

        if (nums[idx] == 0)
            return false;

        if(dp[idx] != -1) return dp[idx];

        int maxIdxReach = idx + nums[idx];

        for (int i = idx + 1; i <= maxIdxReach; i++) {
            if(i<nums.size() && canYouReach(i, nums, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }

public:
// DP solution
    /* bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        if (nums[0] == 0 && nums.size() > 1)
            return false;
        vector<int>dp(nums.size(), - 1);
        return canYouReach(0, nums, dp);
    } */

    // Optimal Greedy Solution
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        if (nums[0] == 0 && nums.size() > 1)
            return false;
        int maxIndex = 0;
        for(int i=0;i<nums.size();i++){
            if(maxIndex>=nums.size()-1) return true;
            maxIndex = max(maxIndex, i+nums[i]);
            if(maxIndex==i) return false;
        }
        return false;
    }
};