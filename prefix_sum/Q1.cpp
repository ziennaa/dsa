/*
LR Sum Query
Solved

Time Limit : 
4 sec
Memory Limit : 
512000 MB
Description
Given an array of 
N
N integers and 
Q
Q queries. In each query two integers 
L
L, 
R
R are given, you have to find the value of 
(
A
[
L
]
+
A
[
L
+
1
]
+
A
[
L
+
2
]
+
⋯
+
A
[
R
]
)
%
1
0
9
+
7
(A[L]+A[L+1]+A[L+2]+⋯+A[R])%10 
9
 +7.

Input Format
The first line contains two space-separated integers 
N
N, 
Q
Q where 
1
≤
N
≤
1
0
6
1≤N≤10 
6
 , 
1
≤
Q
≤
1
0
6
1≤Q≤10 
6
 . The next line contains 
N
N space-separated integers 
A
1
,
A
2
,
…
,
A
N
A 
1
​
 ,A 
2
​
 ,…,A 
N
​
  where 
−
1
0
9
≤
A
i
≤
1
0
9
−10 
9
 ≤A 
i
​
 ≤10 
9
 . The next 
Q
Q lines each contain two space-separated integers 
L
L, 
R
R where 
1
≤
L
≤
R
≤
N
1≤L≤R≤N.

Output Format
For each query print the value of 
(
A
[
L
]
+
A
[
L
+
1
]
+
A
[
L
+
2
]
+
⋯
+
A
[
R
]
)
%
1
0
9
+
7
(A[L]+A[L+1]+A[L+2]+⋯+A[R])%10 
9
 +7 in a new line.

Constraints
1
≤
N
≤
1
0
6
1≤N≤10 
6
 
1
≤
Q
≤
1
0
6
1≤Q≤10 
6
 
−
1
0
9
≤
A
i
≤
1
0
9
−10 
9
 ≤A 
i
​
 ≤10 
9
 
Time limit: 
4
4 seconds

Sample Input 1
10 10
12 -23 -123 2345 2345 44 345 -93945 -5353 1
1 5
1 8
1 10
2 2
6 6
4 8
2 9
4 10
3 6
5 9
Sample Output 1
4556
999911007
999905655
999999984
44
999911141
999905642
999905789
4611
999903443

*/
// precompute outside if you do it inside it'll cause TLE
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int prefix[n];
    prefix[0] = a[0];
    for(int i=1; i<n; i++){
        prefix[i] = (prefix[i-1] % mod + a[i] % mod )%mod;
    }
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        int ans = 0;
        if( l == 0 ){
            ans = prefix[r] % mod;
        }else{
            ans = ( prefix[r] % mod - prefix[l-1] % mod + mod ) % mod;
        }
        //int ans = ( prefix[r] % mod - prefix[l-1] % mod + mod ) % mod;
        if(ans > 0){
            cout << ans % mod <<"\n";
        }else{
            cout << (mod + ans)%mod << "\n";
        }
    }
}
// here tc: o(n+q)
// if u precompute inside tc would be O(n)×q=O(nq)​ and thats why caused tle
