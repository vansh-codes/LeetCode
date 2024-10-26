class Solution {
public:
//  Time Complexity: Worst O(s.size()), Best: O(lastWord.size())
     int lengthOfLastWord(string s) {
        int len = 0, end = s.size() - 1;
        while (end >= 0 && s[end] == ' ')   // ignore last spaces and reach the last character 
            end--;
        while (end >= 0 && s[end] != ' ') { // start reading from last char till another space is encountered
            len++;
            end--;
        }
        return len;
    }
};