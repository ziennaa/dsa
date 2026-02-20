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
    cout << get_subarray_distinct_elements_lessthan_equalto(n, k, a)- get_subarray_distinct_elements_lessthan_equalto(n, k - 1, a) << "\n";
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
