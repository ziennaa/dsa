#include <bits/stdc++.h>
using namespace std;

static const double INF = 1e18;
int n, m, d;
vector<vector<pair<int,int>>> adj;  // adj[u] = list of (v, cost)

bool exists_path_with_avg_le(double mid) {
    // DP over DAG in topological order (nodes are 1..n, edges go u<v)
    static vector<double> dp;
    dp.assign(n+1, INF);
    dp[1] = 0.0;
    for (int u = 1; u <= n; ++u) {
        if (dp[u] == INF) continue;
        for (auto &e : adj[u]) {
            int v = e.first;
            double w = e.second - mid;
            if (dp[u] + w < dp[v]) {
                dp[v] = dp[u] + w;
            }
        }
    }
    return dp[n] <= 0.0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n+1, {});
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }

    // 1) Binary-search the minimal average
    double low = 0.0, high = 100.0;
    for (int it = 0; it < 100; ++it) {
        double mid = (low + high) / 2.0;
        if (exists_path_with_avg_le(mid))
            high = mid;
        else
            low = mid;
    }

    double bestAvg = high;

    // 2) One final DP to reconstruct the path at average = bestAvg
    vector<double> dp(n+1, INF);
    vector<int> parent(n+1, -1);
    dp[1] = 0.0;
    for (int u = 1; u <= n; ++u) {
        if (dp[u] == INF) continue;
        for (auto &e : adj[u]) {
            int v = e.first;
            double w = e.second - bestAvg;
            if (dp[u] + w < dp[v]) {
                dp[v] = dp[u] + w;
                parent[v] = u;
            }
        }
    }

    // 3) Reconstruct path from 1 to n
    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    // 4) Output
    int k = (int)path.size() - 1;
    cout << k << "\n";
    for (int v : path) {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}

/* solution by chatgpt refer later */
