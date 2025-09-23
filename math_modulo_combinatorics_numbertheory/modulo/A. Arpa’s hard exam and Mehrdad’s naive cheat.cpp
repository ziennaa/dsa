#include <bits/stdc++.h>
using namespace std;
#define int long long
int binpow(int a, int b, int p){
    //a = 1378;
    //b = n;
    //p = 1e9+7;
    if(b==0){
        return 1;
    }
    else if(b%2==1){
        return ((a%p)*(binpow(a, b-1, p))%p)%p;
    }
    else{
        int temp = binpow(a, b/2, p);
        return (temp*temp)%p;
    }
}
void solve(int n){
    int a = 1378;
    int b = n;
    int p = 10;
    int res = binpow(a, b, p);
    cout<<res%10<<"\n";
}
signed main(){
    int n;
    cin>>n;
    solve(n);
}
