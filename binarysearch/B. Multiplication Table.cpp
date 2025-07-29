#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, k;
    cin>>n>>k;
    ll low=1;
    ll high=n*n;
    while(low<high){
        ll mid = low+(high-low)/2;
        ll count=0;
        for(int i=1; i<=n; i++){
            count += min(mid/i, n);
        }
        if(count>=k){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    cout<<low<<endl;
}
