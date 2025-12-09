#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int comb[1001][1001];
int ncr(int n, int r){
    comb[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0) comb[i][j] = comb[i-1][j] % mod;
            else comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%mod;
        }
    }
    return comb[n][r];
}
signed main(){
    int n, r;
    cin>>n>>r;
    cout<<ncr(n, r)<<"\n";
    return 0;
}
/*

TC: o(n2)
but here mod works if not prime too so
*/