#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int y = INT_MIN;
    int g = INT_MAX;
    for(int i=0; i<n; i++){
        y=max(a[i], y);
        g=min(a[i], g);
    }
    int dif = y - g;
    int county = 0;
    int countg = 0;
    for(int i=0; i<n; i++){
        if(a[i]==y){
            county++;
        }
        if(a[i]==g){
            countg++;
        }
    }
    if(y==g){
        int noways = (n*(n-1))/2;
        cout<<dif<<" "<<noways<<"\n";
    }else{
        int noways = county*countg;
        cout<<dif<<" "<<noways<<"\n";
    }
}