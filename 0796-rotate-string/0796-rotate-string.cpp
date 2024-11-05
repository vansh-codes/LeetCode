class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            bool isRotationPossible = true;

            for (int j = 0; j < s.size(); j++) {
                if (goal[(i + j) % goal.size()] != s[j]) {
                    isRotationPossible = false;
                    break;
                }
            }

            if (isRotationPossible) {
                return true;
            }
        }

        return false;
    }
};