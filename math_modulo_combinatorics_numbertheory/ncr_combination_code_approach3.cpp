#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int ncr(int n, int r){
    int ans = 1;
    for(int i=1; i<=r; i++){
        ans *= (n-i+1);
        ans /= i;
    }
    return ans;
}
signed main(){
    int n, r;
    cin>>n>>r;
    cout<<ncr(n, r)<<"\n";
    return 0;
}
/*
only works for n <= 40
never overflow within long long range
tc : o(r)*/