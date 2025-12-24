#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int binpow(int a, int b){
    if(b == 0) return 1;
    else if(b%2 == 1) return ((a % mod) * binpow(a, b-1) % mod)%mod;
    else{
        int temp = binpow(a, b/2) % mod;
        return (temp * temp) % mod;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, k;
    cin>>n>>q>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] = (a[i]%mod + mod) % mod;
    }
    vector<int> pref(n);
    pref[0] = a[0];
    for(int i=1; i<n; i++){
        pref[i] =(pref[i-1]+(a[i]*binpow(k, i)%mod)%mod)%mod;
    }
    while (q--)
    {
        /* code */
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        int p = binpow(k, l)%mod; 
        int u = binpow(p, mod-2)%mod;
        int sumQ = pref[r] - (l ? pref[l-1] : 0);
        sumQ = (sumQ % mod + mod )%mod;
        int ans = ((sumQ) * u % mod)%mod;
        if(ans < 0) ans+= mod;
        cout<<ans<<"\n"; 
    }
}