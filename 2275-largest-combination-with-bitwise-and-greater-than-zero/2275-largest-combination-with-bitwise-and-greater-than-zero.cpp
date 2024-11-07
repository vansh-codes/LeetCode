class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(24,0);
        for(int i=0;i<24;i++){
            for(int cand: candidates){
                if((cand & (1<<i)) != 0) bitCount[i]++;
            }
        }
        return *max_element(bitCount.begin(), bitCount.end());
    }
};