class Solution {
private:
    bool isGood(int first, int second, int third, int a, int b, int c) {
        return abs(first - second) <= a && abs(second - third) <= b &&
               abs(first - third) <= c;
    }

public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (isGood(arr[i], arr[j], arr[k], a, b, c)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};