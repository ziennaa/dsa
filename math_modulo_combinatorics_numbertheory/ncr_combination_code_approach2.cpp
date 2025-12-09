/*
 if  n ≤ 10^9 and  r≤20 Previous code won't work as fact(n) 
would get very large (will loop till 10^9 )
*/
/*
here instead of doing 
ncr i.e n!/ n-r ! * r! 
we're calculating
ncr i.e n* n-1* n-2 * .... * n-r+1 / r! */
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int binpow(int a, int b){
    if(b==0) return 1;
    else if(b%2==1) return (a%mod)*(binpow(a, b-1)%mod)%mod;
    else{
        int temp = binpow(a, b/2)%mod;
        return temp*temp%mod;
    }
}
int inverse(int x){
    return binpow(x, mod-2);
}
int ncr(int n, int r){
    int num = 1, den=1;
    for(int i=1; i<=r; i++){
        num = (num*(n-i+1))%mod;
        den = (den * i) % mod;
    }
    return (num * inverse(den)) % mod;
}
signed main(){
    int n, r;
    cin>>n>>r;
    cout<<ncr(n, r)<<"\n";
    return 0;
}
/*
TC : O(r)
 Infact you could also loop 'i' till min(r, n-r), that will still work. 
 You wanna cancel out larger one and loop for smaller one, among 
O(min(r,n−r)) Technically, this code is always better to use than code in Approach - 1
*/