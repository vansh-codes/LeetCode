class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr){
        vector<int> nse(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> prevSmallerAndEqualElement(vector<int> arr){
        vector<int> psee(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmallerElement(arr);
        vector<int> psee = prevSmallerAndEqualElement(arr);
        int left = 0, right = 0, total = 0, mod = (int)(1e9+7);
        for(int i=0;i<arr.size();i++){
            left = i - psee[i];
            right = nse[i] - i;
            total = (total + left * right * 1LL * arr[i]) % mod;
        }
        return total;
    }
};