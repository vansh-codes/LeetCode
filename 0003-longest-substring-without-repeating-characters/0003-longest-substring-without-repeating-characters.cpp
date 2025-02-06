class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1)
            return 1;
        int l = 0, r = 0, maxLen = 0;
        vector<int> hash(256, -1);
        while (r < s.size()) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) { // already exists and repeats in considered window
                l = hash[s[r]] + 1;                    // then we update l and move forward
            }
            int len = r - l + 1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};