#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>a[i][j];
            }
        }
        ll total = 0;
        for(int j=0; j<m; j++){
            vector<int> col;
            for(int i=0; i<n; i++){
                col.push_back(a[i][j]);
            }
            sort(col.begin(), col.end());
            for(int i=0; i<n; i++){
                ll value = col[i];
                ll contri = value*(2LL*i-n+1);
                total += contri;
            }
        }
        cout<<total<<endl;

    }
}
