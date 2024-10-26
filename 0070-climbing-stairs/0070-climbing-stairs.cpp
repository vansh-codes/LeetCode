class Solution {
public:
    // O(n) &  O(n)
    /* int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2) {
            return n;
        }
        int arr[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        for (int i = 3; i < n + 1; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    } */

    // O(n) & O(1) -> Space optimized
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1;
        for(int i=2;i<=n;i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};