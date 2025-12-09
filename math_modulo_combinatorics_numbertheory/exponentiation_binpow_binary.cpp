#include <bits/stdc++.h>
using namespace std;
#define int long long
int binpow(int a, int b, int mod){
    a %= mod;
    int res = 1;
    while(b>0){
        if(b&1) res = res*a %mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
signed main(){
    int a, b;
    cin>>a>>b;
    int mod = 1e9+7;
    cout<<binpow(a, b, mod)<<"\n";
    return 0;
}
