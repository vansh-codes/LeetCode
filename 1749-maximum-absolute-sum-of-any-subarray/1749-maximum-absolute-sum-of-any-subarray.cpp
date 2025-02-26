class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = 0, maxPrefixSum = 0;

        int prefixSum = 0;
        for (int num: nums) {
            prefixSum += num;

            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }

        return maxPrefixSum - minPrefixSum;
    }
};