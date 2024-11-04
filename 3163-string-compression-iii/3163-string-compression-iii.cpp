class Solution {
public:
    string compressedString(string word) {
        map<char, int> mp;
        string comp = "";
        for (int i = 0; i < word.size(); i++) {
            if (mp[word[i]] >= 9) {
                comp += to_string(mp[word[i]]);
                comp += word[i];
                mp[word[i]] = 0;
            }
            mp[word[i]]++;
            if (word[i + 1] != word[i]) {
                comp += to_string(mp[word[i]]);
                comp += word[i];
                mp[word[i]] = 0;
            }
        }
        // for(auto i: mp){
        //     while(i.second>9){
        //         comp += "9";
        //         comp += i.first;
        //         i.second -= 9;
        //     }
        //     comp += (to_string(i.second)+i.first);
        // }
        return comp;
    }
};