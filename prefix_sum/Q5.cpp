#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> ar(n, 0);
    //vector<int> pref(n, 0);
    //pref[0] = 0;
    //for(int i=1; i<n; i++){
    //    pref[i] = pref[i-1] + i;
    //}
    vector<int> pref(n, 0);
    vector<int> pref2(n, 0);
    vector<int> ans(n, 0);
    vector<int> dem(n, 0);
    while(q--){
        int a, d, l, r;
        cin>>a>>d>>l>>r;
        l--;
        r--;
        int sam = ((a%mod)-(d*l)%mod + mod)%mod; 
        //vector<int> dem(n);
        ar[l] += sam % mod ;
        if(r+1<n){
            ar[r+1] -= sam;
        }
        dem[l] += d % mod;
        if(r+1 < n){
            dem[r+1] -= d;
        }
    }
    pref[0] = ar[0];
    pref2[0] = dem[0];
    ans[0] = pref[0];
    for(int i=1; i<n; i++){
        pref[i] = ( pref[i-1] + ar[i] ) % mod;
        pref2[i] = (pref2[i-1] + (dem[i]))%mod;
        ans[i] = ((pref[i] % mod) + (i%mod*pref2[i]%mod)%mod) % mod;
    }
    for(int it: ans){
        cout<<( it % mod + mod ) % mod<<" ";
    }
}