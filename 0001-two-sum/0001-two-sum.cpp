class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force
        /* for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                    {
                        if(nums[i]+nums[j]==target)
                            {
                                return {i,j};
                            }
                    }
            }
        return {-1,-1}; */

        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            int left = target-nums[i];
            if(mp.find(left) != mp.end()){
                return {mp[left],i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};