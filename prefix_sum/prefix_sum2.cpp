/*
Given an array A of size N,
 initially all 0's. There are Q queries of the form:
  +LRx -> add x to all indices in the range [L, R].
   After all queries, you need to find the final array.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> a(n, 0);
    while(q--){
        int l, r, x;
        cin>>l>>r>>x;
        a[l] += x;
        if(r+1<n){
            a[r+1] -= x;
        }
    }
    for(int i=1; i<n; i++){
        a[i]  += a[i-1];
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}
/*
// TC : O(n+q*1)
“add X to range”

“range updates, final array needed”

“many queries”
*/
//Let’s say the final array is formed by:
    // final[i] = sum of all changes affecting i
/*
a[l]     += x;
a[r + 1] -= x;
*/
// a[1] += 3
// a[5] -= 3
// [0, 3, 0, 0, 0, -3]
/*
i=0 → 0
i=1 → 3
i=2 → 3
i=3 → 3
i=4 → 3
i=5 → 0
//Exactly what the query wanted — without touching every index.
*/