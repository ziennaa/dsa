#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        const int MAXL=200005;
        int n;
        cin>>n;
        int a[n];
        int freq[MAXL]={0};
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<=n; i++) freq[i]=0;
        for(int i=0; i<n; i++){
            freq[a[i]]++;
        }
        int maxx=0;
        for(int i=0; i<=n; i++){
            if(maxx<freq[i]){
                maxx=freq[i];
            }
        }
        int used = 0;
        for (int i = 0; i < MAXL; i++) {
            if (freq[i] > 0) used++;
        }
        if(used<=2){
            cout<<1<<endl;
        }else{
            cout<<maxx<<endl;
        }
    }
}
// wrong ans
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        const int MAXL = 200005;
        int n;
        cin >> n;
        int a[n];
        int freq[MAXL] = {0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i <= n; i++) {
            freq[i] = 0;
        }
 
        for(int i = 0; i < n; i++){
            freq[a[i]]++;
        }
 
        int maxx = 0;
        for(int i = 0; i <= n; i++){
            maxx = max(maxx, freq[i]);
        }
         vector<int> usedFreq;
        for (int i = 0; i < MAXL; i++) {
            if (freq[i] > 0)
                usedFreq.push_back(freq[i]);
        }
 
        int ans;
        if(usedFreq.size() <= 2){
            if(usedFreq.size() == 2){
                if(usedFreq[0] == usedFreq[1])
                    ans = usedFreq[0];
                else
                    ans = 1;
            } else {
                ans = 1;
            }
        } else {
            ans = maxx;
        }
 
        cout << ans << endl;
    }
    return 0;
}

// worked for first 8 test cases but then an error occurredddd🥀🥀💔💔

