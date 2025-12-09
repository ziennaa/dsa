#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int binpow(int a, int b) {
	if(b == 0) return 1;
	if(b % 2 == 1) return (a * binpow(a, b-1)) % mod;
	else {
		int x = binpow(a, b/2);
		return (x * x) % mod;
	}
}

int inverse(int x) {    
	return binpow(x, mod-2);
}
int fact[1000100];
int invfact[1000100];
void fast_precompute(){
    fact[0] = 1;
    for(int i=1; i<=1000000; i++){
        fact[i] = fact[i-1]*i % mod;
    }
    invfact[1000000] = inverse(fact[1000000]);
    for(int i=1000000; i>=1; i--){
        invfact[i-1] = invfact[i]*i%mod;
    }
}
int ncr(int n, int r){
    int num = fact[n];
    int den = invfact[n-r] * invfact[r] % mod;
    return num*den % mod;
}
signed main(){
    fast_precompute();
    int n, r;
    cin>>n>>r;
    cout<<ncr(n, r)<<"\n";
    return 0;
}
/*
tc: o(n+log mod + q)
where q is queres
per query its o(1)*/