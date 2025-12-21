#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, d;
        cin>>n>>d;
        string ans = "";
        if (n == 0)
        {
            cout << "0\n";
            continue;
        }
        if (d == 1)
        {
            ans += to_string(n);
            cout << ans << "\n";
            continue;
        }
        if( (n<0) ^ (d<0) ){
            ans += "-";
        }
        n = llabs(n);
        d = llabs(d);
        //if(n == 0){
        //    cout << "0\n";
        //    continue;
        //}
        //if(d == 1){
        //    ans += to_string(n);
        //    cout<<ans<<"\n";
        //    continue;
        //}
        int q = n/d;
        int r = n%d;
        ans += to_string(q);
        if(r == 0){
            cout<<ans<<"\n";
            continue;
        }
        ans += ".";
        string dec = "";
        vector<int> pos(d, -1);
        while(r != 0 && pos[r] == -1){
            pos[r] = (int)dec.size();
            r *= 10;
            int digit = r/d;
            dec.push_back(char('0'+digit));
            r %= d;
        }
        if(r == 0){
            ans += dec;
        }else{
            int start = pos[r];
            ans += dec.substr(0, start);
            ans+="(";
            ans+=dec.substr(start);
            ans+=")";
        }
        cout<<ans<<"\n";
    }
}

// oa !!!
