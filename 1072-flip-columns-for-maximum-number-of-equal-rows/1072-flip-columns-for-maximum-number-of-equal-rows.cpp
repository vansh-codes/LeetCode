class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternFreq;

        for (auto& currentRow : matrix) {
            string patternBuilder = "";

            for (int col = 0; col < currentRow.size(); col++) {
                if (currentRow[0] == currentRow[col]) {
                    patternBuilder += "T";
                } else {
                    patternBuilder += "F";
                }
            }

            patternFreq[patternBuilder]++;
        }

        int maxFrequency = 0;
        for (auto& entry : patternFreq) {
            maxFrequency = max(entry.second, maxFrequency);
        }

        return maxFrequency;
    }
};