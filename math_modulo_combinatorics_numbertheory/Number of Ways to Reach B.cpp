/*Description
You are given a grid of 
(
N
+
1
)
(N+1) x 
(
M
+
1
)
(M+1). You are initially at position 
A
(
0
,
0
)
A(0,0) and you want to reach 
B
(
N
,
M
)
B(N,M). From a given cell 
(
i
,
j
)
(i,j), you are allowed to move to cells 
(
i
+
1
,
j
)
(i+1,j) and 
(
i
,
j
+
1
)
(i,j+1) only. Find the number of different ways to reach 
B
B from 
A
A.

Input Format
The first line contains 
T
T (
1
≤
T
≤
100000
1≤T≤100000), the number of test cases. Each of the next 
T
T lines contains two positive integers 
N
,
M
N,M (
1
≤
N
,
M
≤
1
0
5
1≤N,M≤10 
5
 ).

Output Format
For each test case, print the number of ways to reach 
B
B from 
A
A. Since the answer can be large, print it modulo 
1000000007
1000000007.

Constraints
1
≤
T
≤
100000
1≤T≤100000
1
≤
N
,
M
≤
1
0
5
1≤N,M≤10 
5
 
It is guaranteed that 
N
+
M
≤
2
⋅
1
0
5
N+M≤2⋅10 
5
  across inputs where necessary for precomputation.

Sample Input 1
2
2 1
3 2
Sample Output 1
3
10





*/












#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int binpow(int a, int b){
    if(b==0) return 1;
    else if(b%2 == 1) return ( (a%mod)*(binpow(a, b-1))%mod )%mod;
    else{
        int temp = binpow(a, b/2)%mod;
        return temp*temp % mod;
    }
}
int inverse(int x){
    return binpow(x, mod-2);
}
int fact[1000100];
void precompute(){
    fact[0] = 1;
    for(int i=1; i<=1000000; i++){
        fact[i] = fact[i-1]*i % mod;
    }
}
int ncr(int n, int r){
    int num = fact[n];
    int den = fact[n-r] * fact[r] % mod;
    return num * inverse(den) % mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    precompute();
    while(t--){
        int n, m;
        cin>>n>>m;
        int p = n+m;
        // calculate pcn
        cout<<ncr(p, n)<<"\n";
    }
}
