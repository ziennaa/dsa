#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int> primeFactorise(long long x){
    map<int, int> factors;
    while(x%2==0){
        factors[2]++;
        x /= 2;
    }
    for(int i=3; i*i<=x; i+=2){
        while(x%i==0){
            factors[i]++;
            x /= i;
        }
    }
    if(x>1){
        factors[x]++;
    }
    return factors;
}
// same thing use this
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
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    auto factors = primeFactorise(x);
    cout<<"Prime Factorisation: \n";
    for(auto p: factors){
        cout<<p.first<<"^"<<p.second<<"\n";
    }
}

