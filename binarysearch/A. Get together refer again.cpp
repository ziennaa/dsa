#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n;
double x[MAXN],v[MAXN];
bool canmeet(double t){
    double left = -1e18;
    double right = 1e18;
    for(int i = 0; i < n; i++){
        double l = x[i] - v[i] * t;
        double r = x[i] + v[i] * t;
        left = max(left, l);
        right = min(right, r);
    }
    return left<=right;
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x[i]>>v[i];
    }
    double low=0;
    double high=1e18;
    for(int i=0; i<100; i++){
        double mid = (low + high)/2;
        if(canmeet(mid)){
            high = mid;
        } else {
            low = mid;
        }
    }
    cout<<fixed<<setprecision(10)<<low<<endl;
}
