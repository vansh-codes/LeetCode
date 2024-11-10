class Solution {
private:
    void updateWindow(vector<int>& bits, int x, int update) {
        for (int i = 0; i < 32; i++) {
            if ((x >> i) & 1)
                bits[i] += update;
        }
    }

    int bitsToNum(vector<int>& bits) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i])
                res |= 1 << i;
        }
        return res;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), res = n + 1;
        vector<int> bits(32);
        for (int st = 0, end = 0; end < n; end++) {
            updateWindow(bits, nums[end], 1);
            while (st <= end && bitsToNum(bits) >= k) {
                res = min(res, end - st + 1);
                updateWindow(bits, nums[st++], -1);
            }
        }
        return res != n + 1 ? res : -1;
    }
};