#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k, q;
    cin>>n>>k>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int ans =  0;
    int len = 0;
    for(auto i : a){
        if(i<=q){
            len+=1;
        }else{
            if(len>=k){
                ans += ((len-k+1)*(len-k+2))/2;
            }
            len=0;
        }
    }
    if(len>=k){
        ans += ((len-k+1)*(len-k+2))/2;
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
