#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, d;
vector<pair<int, int>> adj[N]; // adjacency list: node -> (neighbour, edge weight)
int parent[N];                 // to store the parent of each node (for path)
int dist[N];                   // to store number of edges used to reach each node
bool isPossible(int maxEdgeWeight) {
    // clear visited info
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (w > maxEdgeWeight) continue;
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return dist[n] <= d;
}
int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    int low = 0, high = 1e9;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans == -1) {
        cout << -1 << endl;
        return 0;
    }
    // find actual path now
    isPossible(ans);
    vector<int> path;
    int current = n;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << endl;
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}



/*
 refer to this question after
bfs
dfs
dp
do this after learning them*/
