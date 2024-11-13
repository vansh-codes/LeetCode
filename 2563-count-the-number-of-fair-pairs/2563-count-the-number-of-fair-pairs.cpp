class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i=0;i<nums.size();i++){
            int low = lower - nums[i], up = upper - nums[i];
            auto left = lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), up) - nums.begin();
            res += 1LL*(right - left);
        }
        return res;
    }
};