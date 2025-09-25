#include <bits/stdc++.h>
using namespace std;
#define int long long
int binpow(int a, int b, int p){
    if(b==0){
        return 1;
    }
    else if(b%2==1){
        return ((a%p)*((binpow(a, b-1, p))%p))%p;
    }else{
        int temp = binpow(a, b/2, p);
        return (temp*temp)%p;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int p = 1e9+7;
    int res = binpow(2, n, p);
    cout<<res<<"\n";
}