/*


  Description
Find the number of diagonals in the Convex 
N
N-gon.

A diagonal of a polygon is a line segment joining two non-adjacent vertices. For a convex polygon with 
N
N vertices, compute how many diagonals it has. Since the answer can be large, output it modulo 
1000000007
1000000007.


  */


#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = n*(n-3) / 2;
        ans = (ans)%mod;
        cout<<ans<<"\n";
    }
}
