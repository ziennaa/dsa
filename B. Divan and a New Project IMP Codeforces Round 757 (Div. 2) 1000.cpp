#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        int b[n+1];
        for(int i=1; i<=n; i++){
            cin>>a[i];
            b[i] = i;
        }
        int x=0;
        for(int i=0; i<n-1; i++){
            for(int j=1; j<n-i; j++){
                if(a[j]<a[j+1]){
                    swap(a[j], a[j+1]);
                    swap(b[j], b[j+1]); 
                }
            }
        }
        int pos[n+1];
        pos[0] = 0;
        int cur=1;
        bool right=true;
        for(int i=1; i<=n; i++){
            if(right){
                pos[b[i]] = cur;
            }else{
                pos[b[i]] = -cur;
                cur++;
            }
            right=!right;
        }
        long long time = 0;
        for(int i=1; i<=n; i++){
            time += 2LL * abs(pos[b[i]])*a[i];
        }
        cout<<time<<endl;
        cout<<0<<" ";
        for(int i=1; i<=n; i++){
            cout<<pos[i]<<" ";
        }
        cout<<endl;
    }
}


// TLE HERE !!!!!!!!
// BUBBLE SORT CAUSING TLEEE

// CORRECTED CODE CHATGPT
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<pair<long long,int>> arr;
        arr.reserve(n);
        for (int i = 1; i <= n; i++) {
            arr.push_back({ a[i], i });
        }

        sort(arr.begin(), arr.end(), [](const pair<long long,int> &A, const pair<long long,int> &B) {
            return A.first > B.first;
        });

        vector<long long> pos(n + 1);
        pos[0] = 0;

        long long totalTime = 0;
        int curDist = 1;
        bool placeRight = true;

        for (int k = 0; k < n; k++) {
            long long visits = arr[k].first;
            int idx = arr[k].second;

            if (placeRight) {
                pos[idx] = curDist;
            } else {
                pos[idx] = -curDist;
                curDist++;
            }
            placeRight = !placeRight;

            totalTime += 2LL * llabs(pos[idx]) * visits;
        }

        cout << totalTime << "\n";
        cout << 0;
        for (int i = 1; i <= n; i++) {
            cout << " " << pos[i];
        }
        cout << "\n";
    }

    return 0;
}
