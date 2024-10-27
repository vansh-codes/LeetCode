class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        for(int i=0;i<spaces.size();i++){
            s.insert(s.begin() + spaces[i] + i, ' ');
        }
        return s;
    }
};