#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        ll even = 0;
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            if ((a & 1) == 0) 
                even++;
        }
        ll ans = even * (even - 1) / 2;
        cout << ans << "\n";
    }
    return 0;
}
