class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1) return;
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid]==1){
                mid++;
            } else if(nums[mid]==2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
// tc1
// 2 0 2 1 1 0
// 0 0 2 1 1 2
// 0 0 2 1 1 2
// 0 0 1 1 2 2
// tc2
// 2 0 1
// 1 0 2
// 0 1 2