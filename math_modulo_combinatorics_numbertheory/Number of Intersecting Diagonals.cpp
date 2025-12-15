/*
Number of Intersecting Diagonals
Solved

Time Limit : 
1 sec
Memory Limit : 
256000 MB
Description
Find the number of unordered pairs of intersecting diagonals in the convex 
N
N-gon. The intersecting point should be inside the polygon.

Input Format
The first line contains 
T
T (
1
≤
T
≤
100000
1≤T≤100000), the number of test cases.
Each of the next 
T
T lines contains a positive integer 
N
N denoting the number of sides of the convex polygon (
3
≤
N
≤
1
0
9
3≤N≤10 
9
 ).

Output Format
For each test case, print a single number denoting the number of intersecting diagonals in the convex 
N
N-gon. Since the answer can be large, print it modulo 
1000000007
1000000007.

Constraints
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
    else if(b%2 == 1) return ((a%mod)*binpow(a, b-1)%mod)%mod;
    else{
        int temp = binpow(a, b/2) % mod;
        return temp*temp % mod;
    }
}
int inverse(int x){
    return binpow(x, mod-2);
}
int fact[1000100];
void precompute(){
    fact[0] = 1;
    for(int i=1; i<=100000; i++){
        fact[i] = fact[i-1]*i%mod;
    }
}
int ncr(int n, int r){
    int num = fact[n];
    int den = fact[n-r] * fact[r] %mod;
    return num * inverse(den) % mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    precompute();
    while(t--){
        int n;
        cin>>n;
        // basically calculate nc4
        cout<<ncr(n, 4)<<"\n";
    }
}

WA
it is calculating nc4 
the n ranges till 10^9
  but precompute only does till 100000
  even if i changes mle and tle would happen
so we did this

  #include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int binpow(int a, int b){
    if(b == 0) return 1;
    else if(b%2 == 1) return ((a%mod)*(binpow(a, b-1)%mod)%mod)%mod;
    else{
        int temp = binpow(a, b/2)%mod;
        return temp*temp %mod;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int inv24 = binpow(24, mod-2);
    while(t--){
        int n;
        cin>>n;
        if(n<4){
            cout<<0<<"\n";
            continue;
        }
        int ans = n;
        ans = ans*(n-1)%mod;
        ans = ans*(n-2)%mod;
        ans = ans*(n-3)%mod;
        ans = ans*inv24 % mod;
        cout<<ans<<"\n";
    }
}
