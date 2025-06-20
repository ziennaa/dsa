#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int pos = false;
        for(int i=1; i<n; i++){
            if(a[i]>=a[i-1]){
                pos = true;
                break;
            }
        }
        if(pos){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
}
// checking if strictly dec or no
// n*n-1 / 2 is the max no of inversions in array
// when does this conditon happen when dtrictly dec worst case
// otherwise fewer steps
// yes if not strictly dec else no
