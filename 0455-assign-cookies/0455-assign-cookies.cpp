class Solution {
public:
    int findContentChildren(vector<int> g, vector<int> s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0;   // pointer for greed factors
        int right = 0;  // pointer for childrens
    
        while(left<s.size() && right<g.size()){
            cout<<"l: "<<left<<endl;
            if(s[left]>=g[right]){
                right++;
            }
            left++;
        }
        return right;
    }
};