class Solution {
private:
    int subarrayWithSumLessThanEqual(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // check this diagram for understanding: https://leetcode.com/problems/binary-subarrays-with-sum/Figures/930_fix/BinarySubarraySum-atMostConcept.png

        // all windows with sum 0,1,2 - all windows with sum 0,1 = all windows with sum 2 ✅
        return subarrayWithSumLessThanEqual(nums, goal) - subarrayWithSumLessThanEqual(nums, goal - 1);
    }
};