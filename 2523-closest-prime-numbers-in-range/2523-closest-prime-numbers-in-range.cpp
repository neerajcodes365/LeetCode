class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2, -1);
        vector<int> store(right + 1, 1);
        int count = 0;
        store[1] = 0;

        for (int i = 2; i <= sqrt(right); i++) 
        {
            if (store[i] == 1) {
                for (int j = i * i; j <= right; j = j + i) 
                {
                    store[j] = 0;
                }
            }
        }

        for (int i = left; i <= right; i++) 
        {
            if (store[i] == 1)
                count++;
        }

        vector<int> primes(count);
        int index = 0;

        for (int i = left; i <= right; i++) 
        {
            if (store[i] == 1)
                primes[index++] = i;
        }

        int diff = INT_MAX;

        for (int i = 0; i < count - 1; i++) 
        {
            if (primes[i + 1] - primes[i] < diff) {
                ans[0] = primes[i];
                ans[1] = primes[i + 1];
                diff = primes[i + 1] - primes[i];
            }
        }

        return ans;
    }
};