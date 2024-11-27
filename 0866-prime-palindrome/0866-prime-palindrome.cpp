class Solution {
public:
    bool isPalindrome(int n){
        string s = to_string(n);
        int left=0, right=s.size()-1;
        while(left<right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }

    bool isPrime(int n){
        if(n<=1) return false;
        if(n==2) return true;
        if(n%2==0) return false;
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        if(n<=2) return 2;
        if(n>=9989900) return 100030001;
        if(n<=11 && isPrime(n)) return n;
        unsigned int temp = n;
        while(true){
            if(isPrime(temp) && isPalindrome(temp)) return temp;
                temp++;
        }
        return 0;
    }
};