#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int const MAXN = 1000;
int arr[MAXN][MAXN];
int p[MAXN][MAXN];
void compute_prefix_sum(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p[i][j] = (arr[i][j] % mod + mod) % mod;
            if (i > 0)
                p[i][j] = (p[i][j] + p[i - 1][j]) % mod;
            if (j > 0)
                p[i][j] = (p[i][j] + p[i][j - 1]) % mod;
            if (i > 0 && j > 0)
                p[i][j] = (p[i][j] - p[i - 1][j - 1] + mod) % mod;
        }
    }
}
int queryP(int x1, int y1, int x2, int y2)
{
    int ans = p[x2][y2];
    if (y1 > 0)
        ans = (ans - p[x2][y1 - 1] + mod) % mod;
    if (x1 > 0)
        ans = (ans - p[x1 - 1][y2] + mod) % mod;
    if (x1 > 0 && y1 > 0)
        ans = (ans + p[x1 - 1][y1 - 1]) % mod;
    return ans % mod;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    compute_prefix_sum(n, m);
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        int res = queryP(x1, y1, x2, y2) % mod;
        cout << res % mod << "\n";
    }
}