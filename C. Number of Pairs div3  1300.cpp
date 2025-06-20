#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, l, r;
        cin>>n>>l>>r;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(), a.end());
        long long count=0;
        for(int i=0; i<n; i++){
                int low = lower_bound(a.begin()+i+1, a.end(), l-a[i]) - a.begin();
                int high = upper_bound(a.begin()+i+1, a.end(), r-a[i]) - a.begin();
                count += (high-low);
        }
        cout<<count<<endl;
    }
}
