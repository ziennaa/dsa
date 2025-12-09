#include <bits/stdc++.h>
using namespace std;
#define int long long
int binpow(int a, int b, int mod){
    if(b==0) return 1;
    else if(b%2==1) return ((a%mod)*(binpow(a, b-1, mod))%mod)%mod;
    else{
        int temp = binpow(a, b/2, mod);
        return temp*temp%mod;
    }
}
signed main(){
    int a, b;
    cin>>a>>b;
    int mod = 1e9+7;
    cout<<binpow(a, b, mod)<<"\n";
    return 0;
}
/*
TC : O(log b) 
*/