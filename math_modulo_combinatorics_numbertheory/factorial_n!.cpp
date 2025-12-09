#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int fact(int x){
    int ans = 1;
    for(int i=2; i<=x; i++){
        ans *= i;
        ans %= mod;
    }
    return ans;
}
signed main(){
    int x;
    cin>>x;
    cout<<fact(x)<<"\n";
    return 0;
}