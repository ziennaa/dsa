#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int check(int mid, int k){
    int count = 0;
    for(int i=1; i<=n; i++){
        count += min(n, mid/i);
        if(count >= k) return 1;
    }
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    k = (n*n+1)/2;
    int low = 1;
    int high = n*n;
    int ans = 0;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(check(mid, k) == 1){
            ans = mid;
            high = mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<"\n";
}