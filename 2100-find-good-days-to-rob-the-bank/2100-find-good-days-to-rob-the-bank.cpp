class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        // edge cases;
        if (time >= security.size())
            return {};

        // prefix: 0 1 2 3 0 0 1
        // suffix: 0 4 3 2 1 0 0
        int n = security.size();
        vector<int> pref(n, 0), suff(n, 0);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                pref[i] = pref[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                suff[i] = suff[i + 1] + 1;
            }
        }

        vector<int> goodDays;
        for (int i = 0; i < n; i++) {
            if (pref[i] >= time && suff[i] >= time)
                goodDays.push_back(i);
        }
        return goodDays;
    }
};