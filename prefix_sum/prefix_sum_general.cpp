#include <bits/stdc++.h>
using namespace std;
#define int long long
int prefixsun(vector<int>& a, int l, int r){
    int n = a.size();
    vector<int> prefix_sum(n);
    prefix_sum[0] = a[0];
    for(int i=1; i<n; i++){
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }
    if(l == 0){
        return prefix_sum[r];
    }else{
        return prefix_sum[r] - prefix_sum[l-1];
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int l, r;
        cin>>l>>r;
        //l--;
        //r--;
        int res = prefixsun(a, l, r);
        cout<<res<<"\n";
    }
}
// TC : O(N) 