class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr) {
        stack<int> st;
        vector<int> nse(arr.size(), arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty())
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> previosSmallerElement(vector<int> arr) {
        stack<int> st;
        vector<int> pse(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmallerElement(heights);
        vector<int> pse = previosSmallerElement(heights);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxArea;
    }
};