class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2) {
            return max(nums[0] * nums[1], max(nums[0], nums[1]));
        }
        int prefixSum = 1, suffixSum = 1, maxProduct = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum == 0)
                prefixSum = 1;
            if (suffixSum == 0)
                suffixSum = 1;
            prefixSum *= nums[i];
            suffixSum *= nums[nums.size() - i - 1];
            maxProduct = max(maxProduct, max(prefixSum, suffixSum));
        }
        return maxProduct;
    }
};

// tc1
// [2,3,-2,4]
// prefixSum = 2,6,-12,-48
// suffixSum = 4,-8,-24,-48

// tc2
// [-2,0,-1]
// prefixSum = -2 0- -1
// suffixSum = -1 0 -2