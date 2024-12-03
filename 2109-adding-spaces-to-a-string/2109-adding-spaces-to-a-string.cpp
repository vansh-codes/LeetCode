class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // TLE
        // for(int i=0;i<spaces.size();i++){
        //     s.insert(s.begin() + spaces[i] + i, ' ');
        // }
        // return s;
        
        string ans = "";
        int pointer = 0;
        for(int i=0;i<s.size();i++){
            if(pointer<spaces.size() && i==spaces[pointer]){
                ans += " ";
                pointer++;
            }
            ans += s[i]; 
        }
        return ans;
    }
};