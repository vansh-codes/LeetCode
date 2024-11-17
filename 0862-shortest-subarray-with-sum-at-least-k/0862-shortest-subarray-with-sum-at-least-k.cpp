class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sums(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }

        vector<int> q(n + 1);
        int low = 0, high = 0, minLen = n + 1;

        for (int i = 0; i < sums.size(); i++) {
            while (high > low && sums[i] >= sums[q[low]] + k) {
                minLen = min(minLen, i - q[low++]);
            }
            while (high > low && sums[i] <= sums[q[high - 1]]) {
                high--;
            }
            q[high++] = i;
        }
        return minLen <= n ? minLen : -1;
    }
};