#include <bits/stdc++.h>
using namespace std;
#define int long long
int binpow(int a, int b, int p){
    if(b==0){
        return 1;
    }
    else if(b%2==1){
        return a*(binpow(a, b-1, p))%p;
    }
    else{
        int temp = binpow(a, b/2, p);
        return (temp*temp)%p;
    }
}
void solve(){
    int a, b;
    cin>>a>>b;
    int p = 1e9+7;
    int res = binpow(a, b, p);
    cout<<res<<"\n";
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
 
/*
in order to do modular arithemetic
1. modular arithemetic is needed almost everywhere so it's needed
1. use long long everywhere as you don't know when overflow occurs
2. use signed main instead of int
3. 2 at a time for calculation
4. for doing modulo for exponentials dont ever use pow
cuz if youre doing pow(5,2) it may give 25.0000 or 24.999 which can be wrong
so use binpow()*/
