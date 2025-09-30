#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool allowed[26] = {false};
    for(int i=0; i<k; i++){
        char c;
        cin>>c;
        allowed[c-'a'] = true;
    }
    int ans = 0;
    int len = 0;
    for(int i=0; i<n; i++){
        if(allowed[s[i] -'a']){
            len++;
        }else{
            ans += (len*(len+1))/2;
            len = 0;
        }
    }
    ans += (len*(len+1))/2;
    cout<<ans<<"\n";

}
