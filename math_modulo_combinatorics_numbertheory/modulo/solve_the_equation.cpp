/*
Description
You are given an equation of the form 
(
a
 op1 
b
 op2 
c
)
 mod 
p
(a op1 b op2 c) mod p, where 
op1
op1 and 
op2
op2 are operators which can be 
+
,
−
,
∗
,
/
+,−,∗,/. It is guaranteed that 
(
a
,
p
)
=
(
b
,
p
)
=
(
c
,
p
)
=
1
(a,p)=(b,p)=(c,p)=1 and 
p
p is a prime number. Compute the value of the equation so that the result belongs to 
0
0 to 
p
−
1
p−1.

Operators follow standard mathematical precedence rules (i.e., multiplication and division are evaluated before addition and subtraction).

Note that 
(
x
,
y
)
=
1
(x,y)=1 denotes that 
x
x and 
y
y are coprime.

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
T lines contains an equation in the form 
(
a
 op1 
b
 op2 
c
)
 mod 
p
(a op1 b op2 c) mod p (
1
≤
a
,
b
,
c
,
p
≤
1
0
9
1≤a,b,c,p≤10 
9
 ). It is guaranteed that 
(
a
,
p
)
=
(
b
,
p
)
=
(
c
,
p
)
=
1
(a,p)=(b,p)=(c,p)=1 and 
p
p is a prime number.

Output Format
For each test case, print a single number denoting the value of the equation. Since it is 
mod p
mod p, the value must belong to 
0
0 to 
p
−
1
p−1.

Constraints
1
≤
T
≤
100000
1≤T≤100000.
1
≤
a
,
b
,
c
,
p
≤
1
0
9
1≤a,b,c,p≤10 
9
 . It is guaranteed that 
(
a
,
p
)
=
(
b
,
p
)
=
(
c
,
p
)
=
1
(a,p)=(b,p)=(c,p)=1 and 
p
p is a prime number.

Sample Input 1
2
(1 + 2 / 1) mod 3
(2 * 3 - 8) mod 5
(2∗3−8)mod5=(6−8)mod5=(−2)mod5=3.
*/



// Write your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long
int binpow(int a, int b, int p){
    if(b==0){
        return 1;
    }
    else if(b%2==1){
        return ((a%p)*(binpow(a, b-1, p))%p)%p;
    }else{
        int temp = binpow(a, b/2, p);
        return (temp*temp)%p;
    }
}
int modinv(int a, int p){
    int inv = binpow(a%p, p-2, p);
    return inv;
}
void solve(){
    string s;
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(), '('), s.end());
    s.erase(remove(s.begin(), s.end(), ')'), s.end());
    stringstream ss(s);
    int a, b, c, p;
    char op1, op2;
    string modword;
    ss>>a>>op1>>b>>op2>>c>>modword>>p;
    auto apply = [&](int x, char op, int y, int p){
        if(op == '+') return (x+y)%p;
        if(op == '-') return (x-y+p)%p;
        if(op == '*') return (x*y)%p;
        if(op == '/'){
            int inv = modinv(y, p);
            return (x*inv)%p;
        }
        //return 0;
    };
    int res;
    if(op1 == '*' || op1 == '/'){
        int tmp = apply(a, op1, b, p);
        res = apply(tmp, op2, c, p);
    }
    else if(op2 == '*' || op2 == '/'){
        int tmp = apply(b, op2, c, p);
        res = apply(a, op1, tmp, p);
    }else{
        res = apply(a, op1, b, p);
        res = apply(res, op2, c, p);
    }
    cout<<(res%p+p)%p<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        solve();
    }
}
