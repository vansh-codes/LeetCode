class Solution {
public:
    // view notes for approach
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zeroes = 0, maxLen = 0, n = nums.size();
        // O(2N) Solution \U0001f447
        /* while (r < n) { // O(N)
            if (nums[r] == 0) {
                zeroes++;
                while (zeroes > k) {    // O(N)
                    if (nums[l] == 0) {
                        zeroes--;
                    }
                    l++;
                }
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        } */

        // O(N) Solution \U0001f447
        while (r < n) {
            if (nums[r] == 0) {
                zeroes++;
            }
            if (zeroes > k) {       // if zeroes > k then move the left pointer
                if (nums[l] == 0)   // if zero encountered then decrement zero count and move left pointer
                    zeroes--;
                l++;
            }
            if (zeroes <= k) {      // if zeroes <= k, then only compute maxLen
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};