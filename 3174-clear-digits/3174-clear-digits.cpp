class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                st.push(s[i]);
            }
            if(!st.empty() && isdigit(s[i])){
                st.pop();
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};