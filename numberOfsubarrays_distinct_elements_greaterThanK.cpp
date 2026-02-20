/*
initial thought process 
reverse 
in the program of number of subaarys having distinct elements
less than equal to k 
in that we had k <= distinct
so reverse it
THIS IS WRONG!!!
*/
// first lets see why k<= distinct condition works
// fix tail 
/*
farthest you can extend is head right ?
[tail .. head]
has distinct <=  k then every shorter one is also valid
like 
[tail tail]
[tail tail+1]
.
. 
[tail head]
*/
/*
now what happens when k>= distinct
fix tail again
now consider ends head
[tail .. head] has distinct >= k
making it longer keeps it valid*/
// [ 1 2 1 3 ] k=2
// tail = 0
// 1 2
// 1 2 1
// 1 2 1 3
// count = 3
// but 1 is not valid
// so its more like
// [tail r0]

// total subarrays - no of subarrays <= k-1
// >= k  ==  total subarrays - no of subarrays <= k-1

#include <bits/stdc++.h>
using namespace std;
int distinct = 0;
int freq[1000100];
int n, k;
int a[1000100];
// <= k (given k i.e passed)
int get_subarray_distinct_elements_lessthan_equalto(int n, int k, int a[])
{
    int tail = 0;
    int head = -1;
    map<int, int> mp; // data structure for the problem to store : this is changeable
    int distinct = 0; // to store values this is too changeable
    int ans = 0;
    ;
    while (tail < n)
    {
        while (head + 1 < n && (distinct < k || freq[a[head + 1]] >= 1))
        {
            // (distinct <= k || mp[a[head+1]] >= 1 changeable
            // also here why is it distinct < k and not <= k ??
            // what's our condition ?
            // keep increasing head as long as adding the next element will
            // still keep the window valid
            // will this work ? x = a[head+1] added will distinct stay <= k
            // mp[x] > 0 : x already exists -> distinct doesnt increase
            // if mp[x] == 0 : x is new -> distinct increases by one
            // so adding allowed when we still have room for new distinct < k
            // x is not new mp[x] > 0
            head++;
            if (freq[a[head]] == 0)
            {
                distinct++;
            }
            // distinct++;
            freq[a[head]]++;
        }
        ans += (head - tail + 1); // changeable depending upon what needs to be done
        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            freq[a[tail]]--;
            if (freq[a[tail]] == 0)
            {
                distinct--;
            }
            tail++;
        }
    }
    return ans;
}
void solve()
{
    // int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << ((n*(n+1))/2) - get_subarray_distinct_elements_lessthan_equalto(n, k-1, a) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

// here distinct and freq -> globally declared
// but how will it get cleared ??
// global hai toh clear karna padega na
// here we dont have to clear
// at the end it'll get cleared on it's own
// 1 2 1 3
// and cleared not just in this problem
// but in every problem
/*
You only ever do freq[a[head]]++ when you include an element

And you do freq[a[tail]]-- when you move tail past elements

By the time tail == n, you have removed everything you ever inserted

So the window is empty → all the counts you touched should come back to
*/