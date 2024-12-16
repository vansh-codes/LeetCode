class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            // Find the index of the minimum value
            int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();

            // Replace the minimum value with the multiplied value
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};