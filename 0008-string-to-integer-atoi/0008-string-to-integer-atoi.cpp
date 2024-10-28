class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long num = 0;
        int itr = 0;
        while(s[itr] == ' ') itr++;             // skip all white spaces
        bool negative = s[itr] == '-';          // chcek for negative
        if(s[itr]=='+' || s[itr]=='-') itr++;   // if + or - then increment itr

        while(itr<n && isdigit(s[itr])){        // loop until we have numbers, if character found then break
            num = num*10 + (s[itr]-'0');        // form number
            if(num > INT_MAX || (negative && -num < INT_MIN)){  // check if overflows, to prevent unnecessary iterations after crossing overflow or underflow
                return negative ? INT_MIN : INT_MAX;
            }
            itr++;
        }
        return negative ? -num : num;
    }
};