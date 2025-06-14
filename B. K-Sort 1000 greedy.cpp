#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        long long pm=0;
        long long s=0;
        long long mx=0;
        for(int i=0; i<n; i++){
            pm = max(pm, (long long) a[i]);
            long long d = pm - a[i];
            s += d;
            mx = max(mx, d);
        }
        cout<<s+mx<<endl;
    }
}
/*
ike s is noting all the differences
d is noting the difference at that instant
pref max keeping track of max starting from left
Total cost = s (total increases) + mx (max layers/rounds needed)
mx basically tracks the number of operation performed in each point
cost = (k₁ + 1) + (k₂ + 1) + (k₃ + 1) + ... for each operation
cost = s*k+m*1
  We want to make it non-decreasing:
[3, 3, 3]

So needed increases:

a[1] = 1 → needs +2

a[2] = 2 → needs +1

So:

s = 3 (we will do three +1 operations)

mx = 2 (maximum raise needed is 2)
*/
