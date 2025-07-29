Binary Search Edu Step 5

1. Kth no in union of segments

A. K-th Number in the Union of Segments

time limit per test0.5 seconds

memory limit per test256 megabytes

Given n segments of integers [l1,r1], [l2,r2], ..., [ln,rn].

Let's write out all the numbers from these segments into an array. If some number contains in more than one segment, then it must appear so many times in the array, how many segments it contains. That is, the length of the array is equal to the sum the number of numbers in all segments.

After that, the array is sorted. Your task is to find the number at the position k (numbering starts from 0) in it.

**Input**

The first line contains integers n and k (1≤n≤50,0≤k≤2⋅109). In the next n lines segments are given in the form of pairs li,ri (−2⋅109≤li≤ri≤2⋅109). It is guaranteed that the k-th number in the union exists.

**Output**

Print the required value.

**Examples**

**Input Copy**

```
2 4
1 3
5 7

```

**Output Copy**

```
6
```

**Input Copy**

```
2 3
1 4
3 5

```

**Output Copy**

```
3
```

**Input Copy**

```
1 1500000091
-1500000000 1500000000

```

**Output Copy**

```
91
```

## My solutions

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin>>n>>k;
    vector<int> a;
    //int count = 0;
    for(long long i=0; i<n; i++){
        long long l, r;
        cin>>l>>r;
        for(long long x=l; x<=r; x++){
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    cout<<a[k]<<endl;
}
```

mle here!! memory level exceeded

pushing every no from l to r for all segments 

and space is 256mb but this is for billions and hence taking too much space

therefore this is the answer

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
vector<pair<ll, ll>> seg;
ll counteq(ll mid){
    ll count = 0;
    for(auto &p : seg){
        ll l = p.first;
        ll r = p.second;
        if(mid<l){
            continue;
            // if mid smaller than segment start so no contibution automatically
        }else if(mid>r){
            count += (r-l+1);
            // mid greater than last or r element so all contributes
        }else{
            count += (mid-l+1);
        }
        if(count > k) return count;
    }
    return count;
}
int main(){
    cin>>n>>k;
    seg.resize(n);
    ll low = LLONG_MAX;
    ll high = LLONG_MIN;
    for(int i=0; i<n; i++){
        ll l, r;
        cin>>l>>r;
        seg[i] = {l, r};
        low = min(low, l);
        high = max(high, r);
    }
        while (low<high)
        {
            /* code */
            ll mid = low + (high - low) / 2;
            if(counteq(mid)>k){
                high = mid;
            }else{
                low= mid+1;
            }
        }
        cout<<low<<endl;
}
```
