#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int const maxn = 1005;
int a[maxn][maxn];
int p[maxn][maxn];
// int diff[maxn][maxn] = {0};
void precompute_prefix(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // p[i][j] =  a[i][j];
            if (i > 0)
                p[i][j] += p[i - 1][j];
            if (j > 0)
                p[i][j] += p[i][j - 1];
            if (i > 0 && j > 0)
                p[i][j] -= p[i - 1][j - 1];
        }
    }
}
void addC(int x1, int y1, int x2, int y2, int c)
{
    p[x1][y1] += c;
    p[x1][y2 + 1] -= c;
    p[x2 + 1][y1] -= c;
    p[x2 + 1][y2 + 1] += c;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    memset(p, 0, sizeof(p));
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        x1--;
        x2--;
        y1--;
        y2--;
        // int mx = 0;
        addC(x1, y1, x2, y2, c);
    }
    precompute_prefix(n, m);
    int mx = LLONG_MIN;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // mx = max(mx, a[i][j]);
            if (p[i][j] > mx)
            {
                mx = p[i][j];
                t = 1;
            }
            else if (p[i][j] == mx)
            {
                t++;
            }
        }
    }
    cout << mx << " " << t;
}