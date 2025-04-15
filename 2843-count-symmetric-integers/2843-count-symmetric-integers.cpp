class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            string num = to_string(i);
            if (num.size() % 2 != 0)
                continue;
            int sum1 = 0, sum2 = 0;
            for (int i = 0; i < num.size() / 2; i++) {
                sum1 += (num[i] - '0');
            }
            for (int i = num.size()/2; i < num.size(); i++) {
                sum2 += (num[i] - '0');
            }
            if(sum1==sum2) count++;
        }
        return count;
    }
};