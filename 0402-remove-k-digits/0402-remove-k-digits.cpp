class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size())
            return "0";
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && (st.top()-'0') > (num[i]-'0') && k>0) {
                cout<<"pop: "<<st.top()<<endl;
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        while(result.size() != 0 && result.back() == '0'){
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        if(result.empty()) return "0";
        return result;
    }
};