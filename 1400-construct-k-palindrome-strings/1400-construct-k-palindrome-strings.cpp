class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k)
            return false;
        if (s.size() == k)
            return true;

        vector<int> freq(26);
        int odds = 0;
        for (char& c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odds++;
            }
        }

        return odds <= k;
    }
};