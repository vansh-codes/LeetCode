class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        if(s1==s2) return true;
        int cnt = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) cnt++;
        }
        cout<<cnt<<endl;
        if(cnt==0 || cnt==2) return true;
        return false;
    }
};