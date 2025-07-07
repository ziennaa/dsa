#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    for(ll i=0; i<k; i++){
        int p;
        cin>>p;
        int l=-1; //a[l]<=x
        int r=n; //a[r]>x
        while(l+1<r){
            int m = (r+l)/2;
            if(a[m]<=p){
                l=m;
            }else{
                r=m;
            }
        }
        cout<<l+1<<'\n';
    }
}
