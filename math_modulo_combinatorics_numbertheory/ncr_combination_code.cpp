#include <bits/stdc++.h>
using namespace std;
#define int long long 
int mod = 1e9+7;
int binpow(int a, int b){
    if(b==0) return 1;
    else if(b%2==1) return ((a%mod)*(binpow(a, b-1))%mod)%mod;
    else{
        int temp = binpow(a, b/2);
        return (temp*temp)%mod;
    }
}
int inverse(int x){
    return binpow(x, mod-2);
}
int fact(int x){
    int res = 1;
    for(int i=1; i<=x; i++){
        res *= i;
        res %= mod;
    }
    return res;
}
int ncr(int n, int r){
    int num = fact(n);
    int den = fact(n-r)*fact(r) % mod;
    return num*inverse(den) % mod;
}
signed main(){
    int n, r;
    cin>>n>>r;
    cout<<ncr(n, r)<<"\n";
    return 0;
}

/*
TC: O(n+r)
*/