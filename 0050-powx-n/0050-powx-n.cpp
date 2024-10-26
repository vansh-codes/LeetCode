class Solution {
public:
    double power(double n, long p, long double res=1.0){
        if(p==0) return res;
        if(p%2==0) return power(n*n, p/2, res);
        return power(n, p-1, n*res);
    }
    double myPow(double n, int p) {
        //long q = p;
        if(p<0) return 1/power(n,abs(p));
        return power(n, (long)abs(p));
    }
};