#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
const int MAXN = 10000;
int Arr[MAXN][MAXN];
int P[MAXN][MAXN];
void compute_prefix_sum(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            P[i][j] += Arr[i][j];
            if(i > 0) P[i][j] += P[i-1][j];
            if(j > 0) P[i][j] += P[i][j-1];
            if(i>0 && j>0) P[i][j] -= P[i-1][j-1];
        }
    }
}
void processQuery(int U, int L, int D, int R, int x){
    Arr[U][L] += x;
    Arr[U][R+1] -= x;
    Arr[D+1][L] -= x;
    Arr[D+1][R+1] += x;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    int Q;
    cin>>Q;
    while(Q--){
        int U, L, D, R, X;
        cin>>U>>L>>D>>R>>X;
        processQuery(U, L, D, R, X);
    }
    compute_prefix_sum(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << P[i][j] << " ";
        }
        cout << "\n";
    }
}