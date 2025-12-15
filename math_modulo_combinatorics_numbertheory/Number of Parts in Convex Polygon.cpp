/*
Description
You are given a convex 
N
N-gon. Draw all the diagonals of the convex 
N
N-gon. Suppose that no three diagonals pass through the same point. Into how many parts is the 
N
N-gon divided?

Input Format
The first line contains 
T
T (
1
≤
T
≤
1
0
5
1≤T≤10 
5
 ), the number of test cases.
Each of the next 
T
T lines contains a positive integer 
N
N (
3
≤
N
≤
1
0
9
3≤N≤10 
9
 ), denoting the number of sides of a convex polygon.

Output Format
For each test case, print a single number denoting the number of parts the convex 
N
N-gon is divided into. Since the answer can be large, print it modulo 
1
0
9
+
7
10 
9
 +7.

Constraints
1
≤
T
≤
1
0
5
1≤T≤10 
5
 
3
≤
N
≤
1
0
9
3≤N≤10 
9
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int binpow(int a, int b){
    if(b==0) return 1;
    else if(b%2 == 1) return ((a%mod)*(binpow(a, b-1)%mod)%mod)%mod;
    else{
        int temp = binpow(a, b/2) % mod;
        return temp*temp % mod;
    }
}
int inverse(int x){
    return binpow(x, mod-2);
}
int ncfour(int n){
    // n*n-1*n-2*n-3/ 24
    int ans = n;
    ans = ans*(n-1)%mod;
    ans = ans*(n-2)%mod;
    ans = ans*(n-3)%mod;
    ans = ans*inverse(24) % mod;
    return ans;
}
int ncthree(int n){
    int ans = n*(n-3) / 2;
    ans = ans % mod;
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p = (1+ncfour(n)+ncthree(n))%mod;
        cout<<p<<"\n";
    }
}
