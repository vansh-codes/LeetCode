class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, currSum = 0;
        int left = 0, right = 0;

        unordered_map<int, int> numIdx;
        while (right < nums.size()) {
            int curr = nums[right];
            int lastOccurrence = (numIdx.count(curr) ? numIdx[curr] : -1);
            while (left <= lastOccurrence || right - left + 1 > k) {
                currSum -= nums[left];
                left++;
            }
            numIdx[curr] = right;
            currSum += nums[right];
            if (right - left + 1 == k) {
                res = max(res, currSum);
            }
            right++;
        }
        return res;
    }
};