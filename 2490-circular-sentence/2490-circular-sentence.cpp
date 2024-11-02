class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0] != sentence[sentence.size()-1]) return false;
        char firstChar = sentence[0];
        char prevChar;
        for(int i=0;i<sentence.size();i++){
            if(i<sentence.size()-1 && sentence[i+1]==' '){
                prevChar = sentence[i];
            }
            else if(i>0 && sentence[i-1]==' ' && sentence[i]!=prevChar)
                return false;
        }
        return true;
    }
};