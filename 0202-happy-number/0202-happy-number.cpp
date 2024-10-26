class Solution {
private:
    int sumSquare(int n){
        int sum = 0;
        while(n){
            sum += pow((n%10),2);
            n /= 10;
        }
        return sum;
    }
    bool kyaTuKhushHai(int n){
        if(n==1 || n==7) return true;
        if(n==2 || n==3 || n==4 || n==5 || n==6 || n==8 || n==9) return false;
        return kyaTuKhushHai(sumSquare(n));
    }
public:
    bool isHappy(int n) {
        return kyaTuKhushHai(n);
    }
};