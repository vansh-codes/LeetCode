class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(),-1);
        stack<int>st;
        for(int i=2*(nums.size()-1);i>=0;i--){
            while(!st.empty() && nums[i%nums.size()]>=st.top()) st.pop();
            if(!st.empty() && i<nums.size()){
                result[i] = st.top();
            }
            st.push(nums[i%nums.size()]);
        }
        return result;
    } 
};