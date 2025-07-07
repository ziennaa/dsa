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
        int l=0;
        int high=n-1;
        bool ok=false;
        while(l<=high){
            int mid=l+(high-l)/2;
            if(p<a[mid]){
                high=mid-1;
            }else if (p>a[mid])
            {    
                l=mid+1;
            }else{
                ok = true;
                break;
            }
            
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
