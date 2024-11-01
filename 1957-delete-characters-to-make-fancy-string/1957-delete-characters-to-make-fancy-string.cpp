class Solution {
public:
    string makeFancyString(string &s) {
        string ans = "";
        int appeared = 0;
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i]!=ans[ans.size()-1]) appeared=0;
            if(appeared>=2) continue;
            ans += s[i];
            appeared+=1;
        }
        return ans;


        /* int appeared = 0;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]) appeared=0;
            if(s[i]==s[i-1]){
                appeared++;
            }
            if(appeared>=2){
                s.erase(s.begin()+i);
                i--;
                // appeared=0;
            }
        }
        return s; */
    }
};