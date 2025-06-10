#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; 
    cin >> T;
    while(T--){
        const int MAXL=200005;
        int n, k;
        cin>>n>>k;
        int a[n];
        int freq[MAXL]={0};
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<=n; i++) freq[i]=0;
        int l=0, currentmax=0, maxlen=0;
        for(int i=0; i<n; i++){
            freq[a[i]]++;
            currentmax = max(currentmax, a[i]);
            while(freq[currentmax]>k){
                freq[a[l]]--;
                l++;
                if(freq[currentmax]==0){
                    currentmax=0;
                    for(int r=1; r<=n; r++){
                        if(freq[r]>0){
                            currentmax = max(currentmax, r);
                        }
                    }
                }
            }
            maxlen = max(maxlen, i-l+1);
        }
        cout<<maxlen<<endl;
    }
    return 0;
}
