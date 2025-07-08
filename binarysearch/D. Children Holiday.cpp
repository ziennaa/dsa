#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int calc(ll z, ll t, ll y, ll time){
    ll time_full_cycle=z*t+y;
    ll full_cycle = time/time_full_cycle;
    ll rem_time= time%time_full_cycle;
    ll extra_balloons= min(rem_time/t, z);
    ll balloons = full_cycle * z + extra_balloons;
    return balloons;
}
int main(){
    ll m, n;
    cin>>m>>n;
    ll t,z,y;
    vector<tuple<ll, ll, ll>> assis(n);
    for(ll i=0; i<n; i++){
        cin>>t>>z>>y;
        assis[i]={t, z, y};
    }
    ll low=0;
    ll high=INT_MAX;
    ll ans=-1;
    while (low<high){
        ll mid=(low+high)/2;
        ll total_balloons=0;
        for(auto[t,z,y]:assis){
            total_balloons += calc(z,t,y, mid);
        }
        if(total_balloons>=m){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    ans=low;
    ll balloons_rem=m;
    vector<ll> result(n);
    for(ll i=0; i<n; i++){
        auto[t,z,y] = assis[i];
        ll b =calc(z,t,y, ans);
        result[i] = min(b, balloons_rem);
        balloons_rem -= result[i];
    }
    cout<<ans<<endl;
    for(ll b: result){
        cout<<b<<" ";
    }
    cout<<endl;
}


/*\
Finds minimum time in which m balloons can be inflated by n assistants.

Simulates each assistant’s work-rest cycle to calculate productivity in given time.

Distributes exactly m balloons among assistants based on what they could do in that time.

Handles all edge cases like: some assistants doing more than needed, rest cycles, etc.

*/
