#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, k;
    cin>>n>>k;
    vector<double long> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];
    double long low =0, high=0;
    for(int i=0; i<n; i++){
        high = max(high, a[i]/b[i]); // max possible ratio
    }
    for(int i=0; i<70; i++){
        double long mid = (low+high)/2.0;
        vector<double> val(n);
        for(int j=0; j<n; j++){
            val[j] = a[j]-mid*b[j];
        }
        sort(val.begin(), val.end(), greater<double>());
        double long sum=0;
        for(int j=0; j<k; j++) sum+=val[j];
        if(sum>=0) low=mid;
        else high=mid;
    }
    cout<<fixed<<setprecision(10)<<low<<endl;
    return 0;
}
