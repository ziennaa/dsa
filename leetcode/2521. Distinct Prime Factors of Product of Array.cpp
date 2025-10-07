class Solution {
public:
    map<int, int> primeFactorise(int n) {
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n>1) mp[n]++;
    return mp;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        map<int, int> total;
        for(int i: nums){
            auto factors = primeFactorise(i);
            for(auto m : factors){
                total[m.first] += m.second;
            }
        }
        return total.size();
    }
};

//
/*
idea:
1. prime factorise
2. multiply the numbers of the array
3. add them in a map
4. count the size of the map
*/
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int mp[1000001] = {0};
        for(auto p : nums){
            for(auto i=2; i*i<=p; i++){
                while(p%i==0){
                    mp[i]++;
                    p/=i;
                }
            }
            if(p > 1) mp[p] = 1;
        }
        int count = 0;
        for(int i = 2; i <= 1000; i++) if(mp[i]) count++;
        return count;
    }
};
// stil can be optimised further
// beats 80%

class Solution {
public:
// store prime till sqrt 1000
    int ps[11] = {2,3,5,7,11,13,17,19,23,29,31};
    int distinctPrimeFactors(vector<int>& nums) {
        // nums[i] <= 1000
        // nums.length <=10^4
        // we only need primes up to sqrt 1000
        int prime[10001] = {0};
        for(int num : nums){
            int n = num; // keep original num
            for(int p : ps){
                if(n % p == 0){
                    prime[p] = 1;
                    while(n % p == 0) n /= p;
                }
            }
            if(n > 1) prime[n] = 1; // leftover large prime
        }
        int count = 0;
        for(int i = 2; i <= 1000; i++)
            if(prime[i]) count++;

        return count;
    }
};

// beats 86%
