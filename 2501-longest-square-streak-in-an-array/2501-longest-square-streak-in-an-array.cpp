class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int>mp;
        int res = -1;
        for(int num: nums) {
            int squareRoot = sqrt(num);
            if(squareRoot*squareRoot == num && mp.find(squareRoot)!=mp.end()) {
                mp[num] = mp[squareRoot]+1;
                res = max(res, mp[num]);
            } else mp[num] = 1;
        }
        return res;
    }
};