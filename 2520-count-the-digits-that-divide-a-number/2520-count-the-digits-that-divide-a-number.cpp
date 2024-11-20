class Solution {
public:
    int countDigits(int num) {
        if(num>=1 && num<=9) return 1;
        int n = num;
        int count=0;
        while(n>0){
            if(num % (n%10) == 0) count++;
            n/=10;
        }
        return count;
    }
};