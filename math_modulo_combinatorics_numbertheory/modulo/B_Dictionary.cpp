#include <bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int x = s[0] - 'a';
        int y = s[1] - 'a';
        int ans = x*25;
        if(y<x) ans+=y+1;
        else ans+=y;
        cout<<ans<<"\n";
    }
}