#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll k;
    cin>>k;
    int count=0;
    for(ll i=0; i<k; i++){
        ll l, r;
        cin>>l>>r;
        int left=0;
        int right=n;
        while (left<right)
        {
            int mid=(left+right)/2;
            if(a[mid]>=l){
                right=mid;
            }else{
                left=mid+1;
            }
            /* code */
        }
        int lower=left;
        left=0;
        right=n;
        while(left<right){
            int mid=(left+right)/2;
            if(a[mid]>r){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        int upper=left;
        count=upper-lower;
        cout<<count<<endl;
    }
}
