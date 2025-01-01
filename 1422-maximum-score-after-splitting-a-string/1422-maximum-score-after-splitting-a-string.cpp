class Solution {
public:
    int maxScore(string s) {
        int ones = 0;   // total number of ones
        int zeros = 0;  // total number of zeroes
        int maxi = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }

            maxi = max(maxi, zeros - ones); // 1 1 1 1 1
        }

        if (s[s.size() - 1] == '1') {
            ones++;
        }

        return maxi + ones; //1 + 4 = 5//
    }
};