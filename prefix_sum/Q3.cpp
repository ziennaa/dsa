#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i] = (a[i] % mod + mod) % mod;
    }
    vector<int> s(n), w(n);
    s[0] = a[0];
    w[0] = a[0];
    for(int i=1; i<n; i++){
        s[i] = (s[i-1] + a[i]) % mod;
        w[i] = (w[i-1] + a[i]*(i+1)) % mod;
    }
    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;
        int sumW = w[r] - (l? w[l-1] : 0);
        int sumS = s[r] - (l? s[l-1] : 0);
        sumW = (sumW % mod + mod) % mod;
        sumS = (sumS % mod + mod) % mod;
        int ans = (sumW - l * sumS) % mod;
        if (ans < 0) ans += mod;
        cout<<ans<<"\n";
    }
}