class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        for (int i = 0; i < s.length(); i++) {
            bool isRotationPossible = true;

            for (int j = 0; j < s.length(); j++) {
                // Use modulo operator to handle rotation
                if (goal[(i + j) % goal.length()] != s[j]) {
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