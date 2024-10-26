class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while (i < j) {
            while (nums[i] % 2 == 0 && i < j) {
                i++;
            }

            while (nums[j] % 2 != 0 && j > i) {
                j--;
            }

            swap(nums[i], nums[j]);
        }
        return nums;
    }
};