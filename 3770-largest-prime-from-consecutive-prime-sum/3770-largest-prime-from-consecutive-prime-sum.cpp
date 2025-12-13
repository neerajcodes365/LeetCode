class Solution {
public:
     
   bool isprime(int num) {
        if(num < 2) return false;
        if(num == 2) return true;
        if(num % 2 == 0) return false;
        for(int i = 3; i * i <= num; i += 2) {
            if(num % i == 0) return false;
        }
        return true;
    }
    
    void helpprime(vector<int>& totalprime, int n) {
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        
        for(int i = 2; i * i <= n; i++) {
            if(sieve[i]) {
                for(int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= n; i++) {
            if(sieve[i]) totalprime.push_back(i);
        }
    }

    int largestPrime(int n) {
        if(n==1)return 0;
        vector<int>totalprime;
        helpprime(totalprime,n);
        long long ans=0;
        long long ogi=2;
        // for(int)
        int i=0;
        while(i<totalprime.size()){

            if(isprime(ans)) ogi=ans;
            ans+=totalprime[i++];
            if(ans>n)break;
        }
        return ogi;

    }
};