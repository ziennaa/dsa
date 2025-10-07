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
