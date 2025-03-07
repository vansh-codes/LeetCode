class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> sieve(right+1, 1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i*i<=right;i++){
            if(sieve[i]){
                for(int j=i*i;j<=right;j+=i){
                    sieve[j] = 0;
                }
            }
        }

        vector<int> primes; // store only primes in given range
        for(int n = left;n<=right;n++){
            if(sieve[n]==1)
                primes.push_back(n);
        }

        int mini = INT_MAX;
        vector<int> closePairs(2, -1);
        if(primes.size()<2) return {-1,-1};
        for(int i=1;i<primes.size();i++){
            int diff = primes[i] - primes[i-1];
            if(diff < mini){
                mini = diff;
                closePairs[0] = primes[i-1];
                closePairs[1] = primes[i];
            }
        }
        return closePairs;
    }
};