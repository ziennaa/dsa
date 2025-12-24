#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int binpow(int a, int b)
{
    int res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> ar(n + 1, 0);
    vector<int> ans(n, 0);
    while (q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        l--;
        r--;
        ar[l] = (ar[l] + a) % mod;
        if (r + 1 < n)
        {
            ar[r + 1] = (ar[r + 1] - (a * binpow(k, r - l + 1)) % mod + mod) % mod;
        }
    }
    ans[0] = ar[0] % mod;
    for (int i = 1; i < n; i++)
    {
        ans[i] = (ar[i] + (ans[i - 1] * k) % mod) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}