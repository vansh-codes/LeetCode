class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<bool> sieve(maxEle + 1, true);
        sieve[1] = false;
        for(int i=2;i*i<=(maxEle+1);i++){
            if(sieve[i]){
                for(int j=i*i;j<=maxEle;j+=i){
                    sieve[j] = false;
                }
            }
        }

        int currValue = 1;
        int i = 0, diff;
        while(i<nums.size()){
            diff = nums[i] - currValue;
            if(diff<0) return false;
            if(sieve[diff] || diff==0){
                i++; currValue++;
            } else{
                currValue++;
            }
        }
        return true;
    }
};