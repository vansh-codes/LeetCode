class Solution {
private:
    int primes(int n){
        if(n<=1) return 0;
        int cnt = 0;
        vector<bool> sieve(n+1, true);
        for(long long i=2;i<n;i++){
            if(sieve[i]){
                for(long long j=i*i;j<=n;j+=i){
                    sieve[j] = false;
                }
                cnt+=1;
            }
        }
        return cnt;
    }

public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        int cnt = primes(n);
        return cnt;
    }
};