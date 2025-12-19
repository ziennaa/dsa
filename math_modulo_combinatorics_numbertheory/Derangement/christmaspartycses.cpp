/*
Time limit: 1.00 s
Memory limit: 512 MB

There are n children at a Christmas party, and each of them has brought a gift. The idea is that everybody will get a gift brought by someone else.
In how many ways can the gifts be distributed?
Input
The only input line has an integer n: the number of children.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
4

Output:
9
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int der[1000100];
void compute(int n){
    der[0] = 1;
    der[1] = 0;
    der[2] = 1;
    for(int i=3; i<=n; i++){
        der[i] = ((i-1)*(der[i-1]+der[i-2]))%mod;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    compute(n);
    cout<<der[n]<<"\n";
    return 0;
}
