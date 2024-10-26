class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, char> mp;
        set<char> st;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=t[i];
                if(st.find(t[i])!=st.end()){    // means pehle se set mein hai
                    return false;
                }
                st.insert(t[i]);
            } else if(mp[s[i]]==t[i]){
                continue;
            } else return false;
        }
        return true;
    }
};