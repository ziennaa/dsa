/*
Description
There are 
N piles of stones in front of you. The 
i-th pile contains A i
​number of stones. You want to find whether it is possible to split each pile into 1
1 or more piles of X (≥2) stones such that each splitted-pile has exactly 
X stones. Note that 
X should be the same for each pile.
  */
// what to do ?
// same x for all
// each ai should be divisble by x
// so need to find gcd
// question says each split pile must have exacvtly x stones
// x >= 2
#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> k(n);
        for(int i=0; i<n; i++){
            cin>>k[i];
        }
        //gcd of array
        int ans = k[0];
        for(int i=1; i<n; i++){
            ans = gcd(ans, k[i]);
        }
        if(ans>1){
            cout<<"Yes"<<"\n";
        }else{
            cout<<"No"<<"\n";
        }

    }
}
