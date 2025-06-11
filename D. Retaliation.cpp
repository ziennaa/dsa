#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,
    cin>>n;
    vector<ll> v(n);
    for(auto &it: v) cin>>it;
    ll y = (2*v[0]-v[1]) / (n+1);
    ll x = v[1] -v[0]+y;
    if(y<0 || x<0){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        v[i] -= x*(i+1);
        v[i] -= y*(n-i);
    }
    for(int i=0; i<n; i++){
        if(v[i]!=0){
            cout<<"NO"<<endl;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}


/*
Yousef wants to explode an array a1,a2,…,an
. An array gets exploded when all of its elements become equal to zero.

In one operation, Yousef can do exactly one of the following:

For every index i
 in a
, decrease ai
 by i
.
For every index i
 in a
, decrease ai
 by n−i+1
.
Your task is to help Yousef determine if it is possible to explode the array using any number of operations.

brute force nahi kar sakte cuz  It is guaranteed that the sum of n
 over all test cases doesn't exceed 2⋅105
.

so this is how you do it
Hint 1
Suppose we did x
 operations of the first type and y
 operations of the second type to explode the array. What must the value of a1
 be?

Hint 2
From the first hint, we know the first element a1=1⋅x+n⋅y
. What about the second element?

Solution 2 (written by yse)
Let's consider the first two elements. Suppose we needed x
 operations of the first type and y
 operations of the second type to explode the array, then we know a1=1⋅x+n⋅y
. For the second element, we know a2=2⋅x+(n−1)⋅y
.

Now, let's solve for x
 and y
. Subtracting a2
 from a1
 gives us

a1—a2⟹x=(x+n⋅y)—(2⋅x+(n—1)⋅y)=y—x=y—a1+a2

Let's substitute y−a1+a2
 for x
 in the first formula.

a1⟹y=(y—a1+a2)+n⋅y=2⋅a1—a2n+1

Now, we have the value of y
, which means we can easily find the value of x
. From the formula x=y−a1+a2
, substitute y
 with its value to get x
. What remains is just to check if the array becomes a1=a2=⋯=an=0
 after all the operations.

*/
