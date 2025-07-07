#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, k;
    cin>>n>>k;
    vector<double> ropes(n);
    double maXlen=0;
    for(int i=0; i<n; i++){
        cin>>ropes[i];
        maXlen=max(maXlen, ropes[i]);
    }
    double l=0.0, r=maXlen;
    for(int i=0; i<100; i++){
        double mid=(l+r)/2.0;
        int p=0;
        for(int j=0; j<n; j++){
            p += int(ropes[i]/mid);
        }
        if(p>=k){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
}


/*
Rope Problem
Let's look at one more problem — the rope problem.
We have n
 ropes, the length of the i
-th rope is ai
. We want to cut k
 pieces of the same length out of them. Of all the cutting methods, you need to choose the one in which the length of the cut pieces is maximum.

To solve this problem, let's make the following function — f(x)
 = is it possible to cut out k
 pieces of length x
. This function behaves almost the same as in the previous problem, but there are some differences.

If we can cut pieces of length x
, then we can cut pieces of smaller size (since they need less length). That is, in binary search, you need to swap zeros and ones in order to transform the function to the general algorithm.
The function now accepts not integer values, but real ones. Sometimes it is beneficial to cut off pieces of non-integer size (for example, if there is only one rope of length 1
 and it needs to be cut into three pieces, then the answer to the problem is 13
.
How to solve the second problem? Let's remember what binary search looked like before. We repeated the cycle until l
 and r
 are adjacent numbers. But with real numbers, this trick will not work, since there are no neighboring real numbers.

Therefore, such tasks can be solved with certain accuracy (it is usually indicated in the conditions). It is necessary to continue the loop as long as the segment [l,r]
 has a length greater than the required precision.

However, this algorithm also has a problem, it can get stuck. This will happen if the numbers l
 and r
 are adjacent in the type double
. Since double
 stores numbers not with arbitrary precision, but only a certain number of digits, then if the numbers l
 and r
 are adjacent, then the middle between them will not be found and it will be equal to either l
 or r
 and the algorithm will run infinitely. This problem appears if the answer is large and the required precision is high enough.

The easiest way to deal with this is not to use a while
 loop, but a for
 loop with a sufficiently large number of iterations (you need at least logmaxAnseps
, where maxAns
 — the maximum possible answer, and eps
 — the required precision). Usually, you can always write 100
 iterations and not think.

The function f(x)
 itself should simply go through all ropes, divide their lengths by x
, and round the resulting number down. That is how many pieces of length x
 we can cut. If the sum of all these numbers is not less than k
, then you need to return 1
, otherwise 0
. It should be noted that the f
 function is not fast. It spends O(n)
 operations, where n
 — is the length of the array. The total complexity will be O(n⋅log1eps)
.

✅ Why 100 Iterations Work
Remember: each binary search step cuts the range in half.
So after k steps, your range becomes:

initial length
/
2
𝑘
initial length/2 
k
 
If you want precision up to 1e-6, and your r - l starts at, say, 1e9 (a rope of max length 1e9), then:

1
𝑒
9
/
2
𝑘
≤
1
𝑒
−
6
⇒
2
𝑘
≥
1
𝑒
15
⇒
𝑘
≥
𝑙
𝑜
𝑔
2
(
1
𝑒
15
)
≈
50
1e9/2 
k
 ≤1e−6⇒2 
k
 ≥1e15⇒k≥log 
2
​
 (1e15)≈50
So:

50–60 iterations already give you 1e-6 precision.

We just use 100 iterations to be extra safe, and it’s still super fast.

*/
