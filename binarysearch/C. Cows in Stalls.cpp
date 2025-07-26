#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll a[100005];
bool isvalid(ll x){
    ll cowsplaced = 1;
    ll lastpos = a[0]; //sorted array
    for(int i=0; i<n; i++){
        if(a[i]-lastpos>=x){
            cowsplaced++;
            lastpos = a[i];
        }
    }
    return(cowsplaced>=k);
}
int main(){
    cin>>n>>k;
    ll p=1e18;
    ll v=-1e18;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        p = min(p, a[i]);
        v = max(v, a[i]);
    }
    ll low=0;
    ll high=v-p;
    int ans=0;
    while (low<=high)
    {
        /* code */
        ll mid = (low+high)/2;
        if(isvalid(mid)){
            ans = mid;
            low = mid+1;

        }else{
            high = mid-1; // if mid valid try for a larger dist
        }
    }
    cout<<ans<<endl;
}
