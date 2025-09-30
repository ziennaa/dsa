#include <bits/stdc++.h>
using namespace std;
#define  int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n%2!=0){
        cout<<0<<"\n";
        return 0;
    }
    int s = n/2;
    int res = floor((s-1)/2);
    cout<<res<<"\n";
}
