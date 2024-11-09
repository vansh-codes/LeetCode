class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xorr = nums[0], maxXor = pow(2, maximumBit) - 1;
        for (int i = 1; i < n; i++)
            xorr ^= nums[i];
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = xorr ^ maxXor;
            xorr ^= nums[n - 1 - i];
        }
        return res;
    }
};