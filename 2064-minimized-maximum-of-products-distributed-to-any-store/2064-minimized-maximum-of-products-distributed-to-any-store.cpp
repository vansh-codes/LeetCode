class Solution {
private:
    bool solve(int n, vector<int>& quantities, int item) {
        if (!item)
            return false;
        int store = 0;
        for (auto q : quantities) {
            store += (q - 1) / item + 1;
            if (store > n)
                return false;
        }
        return true;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(n, quantities, mid)) {
                res = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return res;
    }
};