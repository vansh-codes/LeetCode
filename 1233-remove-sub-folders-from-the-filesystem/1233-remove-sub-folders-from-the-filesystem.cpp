class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for (string& s : folder)
            if (result.empty() || result.back().compare(0, result.back().length(), s, 0, result.back().length()) != 0
                || s[result.back().length()] != '/')
                result.push_back(s);
        return result;
    }
};