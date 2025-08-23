#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(string a, string b){
    if(a+b == b+a) return a<b;
    return a+b<b+a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    string a[n];
    string res = "";
    for(int i=0; i<n; i++){
        cin>>a[i];
        //sort(a, a+n, cmp);
    }
    sort(a, a+n, cmp);
    for(int i=0; i<n; i++){
        res += a[i];
    }
    cout<<res<<"\n";
    
}

