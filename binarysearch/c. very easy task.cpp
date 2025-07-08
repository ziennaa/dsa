#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cop(ll t, int x, int y, int n){
    int timerem = t-min(x,y);
    if (timerem<0){
        return false;
    }
    int copies=(timerem/x)+(timerem/y)+1;
    return copies>=n;
}
int main(){
    ll n, x, y;
    cin>>n>>x>>y;
    ll low=0;
    ll high=INT_MAX;
    while(low<high){
        ll mid=(low+high)/2;
        if(cop(mid, x, y, n)){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    cout<<low<<endl;

}
