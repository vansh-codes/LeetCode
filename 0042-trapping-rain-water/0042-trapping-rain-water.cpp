class Solution {
public:
    int trap(vector<int>& height) {
        // TC O(N) SC O(N)
        int n = height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0], rightMax[n-1] = height[n-1];
        for (int i = 1; i < n - 1; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        // final traversal
        int trappedWater = 0;
        for (int i = 0; i < n; i++) {
            if (leftMax[i] > height[i] && rightMax[i] > height[i])
                trappedWater += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return trappedWater;
    }
};