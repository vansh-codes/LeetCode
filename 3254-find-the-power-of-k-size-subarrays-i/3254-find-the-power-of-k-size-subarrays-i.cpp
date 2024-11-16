class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        vector<int> res;
        int low=0, high=1;
        while(high<nums.size()){
            bool isConsecutive = nums[high] - nums[high-1] == 1;
            if(!isConsecutive){
                while(low < high && low + k - 1 < nums.size()){
                    res.push_back(-1);
                    low++;
                }
                low = high;
            } else if(high-low == k-1){
                res.push_back(nums[high]);
                low++;
            }
            high++;
        }
        return res;
    }
};