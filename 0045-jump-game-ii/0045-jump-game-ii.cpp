class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1 && nums[0]==0) return false;
        if (nums.size() == 1)
            return false;
        int minJumps = 0, maxIndex = 0, currentEnd = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxIndex = max(maxIndex, i + nums[i]);
            if (i == currentEnd) {
                minJumps++;
                currentEnd = maxIndex;
            }
        }
        return minJumps;
    }
};