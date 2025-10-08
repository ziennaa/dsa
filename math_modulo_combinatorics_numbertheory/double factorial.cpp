#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int> primeFactorise(int x){
    map<int, int> factors;
    for(int i=2; i*i<=x; i++){
        while(x%i==0){
            factors[i]++;
            x/=i;
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
        pp *= p;
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
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n%2==1){
        cout<<0<<"\n";
        return 0;
    }
    int c2 = (n/2) + powerFact(n/2, 2);
    int c5 = powerFact(n/2, 5);
    cout<<min(c2, c5)<<"\n";
}
