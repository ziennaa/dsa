#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin>>n;
        int grid[100][100];
        for(int i=0; i<n; i++){
            string row;
            cin>>row;
            for(int j=0; j<n; j++){
                grid[i][j] = row[j]-'0';
            }
        }
        int ans=0;
        for(int i=0; i<(n+1)/2; i++){
            for(int j=0; j<(n/2); j++){
                int x1 = i;
                int y1 = j;
                int x2 = j, y2 = n-i-1;
                int x3 = y2, y3=n-1-x2;
                int x4 = y3, y4 = i;
                int ones = grid[x1][y1] + grid[x2][y2] + grid[x3][y3] + grid[x4][y4];
                ans += min(ones, 4-ones); 
                // ones: number of 1s in 4sysmmetric pos
                // 4-ones is number of zeroes
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
