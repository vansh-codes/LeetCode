class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int blacky = 0, result = INT_MAX;
        
        for (int i = 0; i < blocks.size(); i++) {
            if (i - k >= 0 && blocks[i - k] == 'B') blacky--;
            if (blocks[i] == 'B') blacky++;
            result = min(result, k - blacky);
        }
        
        return result;
    }
};