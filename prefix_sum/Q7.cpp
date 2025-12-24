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
        int n, m, q;
        cin>>n>>m>>q;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        vector<int> cnt(n+2, 0);
        //vector<int> s;
        for(int i=0; i<m; i++){
            int l, r;
            cin>>l>>r;
            cnt[l]++;
            cnt[r+1]--;
            // value a[i]
            // frequency cnt[i]
        }
        for(int i=1; i<=n; i++){
            cnt[i] += cnt[i-1];
        }
        vector<pair <int, int>> freq;
        for(int i=0; i<n; i++){
            if(cnt[i+1]>0){
                freq.push_back({a[i], cnt[i+1]});
            }
        }
        sort(freq.begin(), freq.end());
        for (int i = 1; i <= n; i++)
        {
            freq[i].second += freq[i - 1].second;
        }
        while(q--){
            int k;
            cin>>k;
            if (freq.empty() || k > freq.back().second)
            {
                cout << -1 << " ";
                continue;
            }
            int low=0;
            int high = freq.size()-1;
            while(low<high){
                int mid = low+(high-low)/2;
                if(freq[mid].second >= k){
                    high = mid;
                }else{
                    low = mid+1;
                }
            }
            cout<<freq[low].first<<" ";
        }
        cout<<"\n";
    }
}
