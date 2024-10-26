class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int itrA = a.size() - 1, itrB = b.size() - 1;
        int carry = 0;
        while (itrA >= 0 || itrB >= 0 || carry) {
            if (itrA >= 0) {
                carry += a[itrA--] - '0'; // converts to int
            }
            if (itrB >= 0) {
                carry += b[itrB--] - '0';
            }
            sum += carry % 2 + '0'; // converts to char
            carry /= 2;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};