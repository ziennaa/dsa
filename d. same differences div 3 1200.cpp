#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        map<pair<int, int>, pair<int, int>> m;
        ll count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                m[{i,j}] = {a[i], a[j]};
            }
        }
        for(auto it: m){
            int i = it.first.first;
            int j = it.first.second;
            int ai = it.second.first;
            int aj = it.second.second;
            if((aj-ai)==(j-i)){
                count++;
            }
        }
        cout<<count<<endl;
    }
}

// probably gonna run into tle cuz question says no of test cases to be <= 2.10^5
// so this is clearly misleading but ok for since i just learned maps!!! yes tle happened.
// this is bf and not gonna work!!!!

