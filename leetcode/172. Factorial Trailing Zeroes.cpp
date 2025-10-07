class Solution {
public:
    map<int, int> primeFactorise(int x){
        map<int, int> factors;
        for(int i=2; i*i<=x; i++){
            while(x%i==0){
                factors[i]++;
                x /= i;
            }
        }
        if(x>1) factors[x]++;
        return factors;
    }
    int powerFact(int n, int p){
        int power = 0;
        int pp = p;
        while(pp<=n){
            power += n/pp;
            if(pp>n/p) break;
            pp*=p;
        }
        return power;
    }
   //int largestPower(int n, int x){
   //    auto factors = primeFactorise(x);
   //    int ans = LLONG_MAX;
   //    for (auto [prime, exp] : factors){
   //        long long poww = powerFact(n, prime);
   //        long long y = poww/exp;
   //        ans = min(ans, y);
   //    }
   //    return (int)ans;
   //}
    int trailingZeroes(int n) {
        return (int)powerFact(n, 5);
    }
};
