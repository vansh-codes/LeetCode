class Solution {
public:
    // O(n) time & O(n) space
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        // left pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // right pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                if (candies[i] > candies[i + 1]) {
                    continue;
                }
                candies[i] = candies[i + 1] + 1;
            }
        }

        int totalCandies = 0;
        for (int i = 0; i < n; i++) {
            totalCandies += candies[i];
        }
        return totalCandies;
    }
};

// tc1
// 1 0 2
// initialized with 1 1 1
// left pass: 1 1 2
// right pass: 2 1 2

//  tc2
// 1 2 2
// initialized with 1 1 1
// left pass: 1 2 1
// right pass: 1 2 1