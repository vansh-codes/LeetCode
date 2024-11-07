class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maximumArea = 0;
        while(left<right){
            maximumArea = max(maximumArea, min(height[left], height[right])*(right-left));
            if(height[left]<=height[right]) left++;
            else right--;
        }
        return maximumArea;
    }
};