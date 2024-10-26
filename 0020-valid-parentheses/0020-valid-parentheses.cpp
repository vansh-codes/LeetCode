class Solution {
public:
    bool isValid(string s) {
        if(s.size()==1) return false;
        stack<char> st;
        for(char c: s){
            if(st.empty()){
                if(c=='(' || c=='{' || c=='[')
                st.push(c);
                else return false;
            } else if(c=='(' || c=='{' || c=='['){
                st.push(c);
            } else if(c==')' || c=='}' || c==']'){
                if(st.top() == '(' && c==')') st.pop();
                else if(st.top() == '{' && c=='}') st.pop();
                else if(st.top() == '[' && c==']') st.pop();
                else return false;
            }
        }
        return true;
    }
};