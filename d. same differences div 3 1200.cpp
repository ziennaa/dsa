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
        ll count=0;
        map<ll, ll> m;
        for(int i=0; i<n; i++){
             cin>>a[i];
             ll x =a[i]-i;
             count += m[x];
             m[x]++;
        }
        cout<<count<<endl;
    }
}

// worked within tle
// herre basically
/*
say b[i] = a[i]-i
cuz j-i == a[j]-a[i]
    and so a[j]-j = a[i]-i
    so lets say a[j]-j= b[i]
    and so everytime b[i]==a[i]-i
    we know its a match and so we get it
*/

// there's another sol
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        map<long long, long long> mp;
        for(long long i=0; i<n; i++){
            cin>>a[i];
            mp[a[i]-i]++;
        }
        long long ans=0;
        for(auto it: mp){
            ans+=(it.second*(it.second-1))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}

// this is a valid formula
// if you know indices it occurs at then you can do
// f*(f-1)/2 to find no of pairs

