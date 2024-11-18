class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0)
            return res;
        if (k > 0) {
            int wSum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            res[0] = wSum;
            for (int l = 1, r = k + 1; l < n; r++, l++) {
                wSum += -code[l] + code[r % n];
                res[l] = wSum;
            }
            return res;
        }
        k = -k;
        int wSum = accumulate(code.end() - k, code.end(), 0);
        res[0] = wSum;
        for (int r = 0, l = n - k; r < n - 1; r++, l++) {
            wSum += -code[l % n] + code[r];
            res[r + 1] = wSum;
        }
        return res;
    }
};