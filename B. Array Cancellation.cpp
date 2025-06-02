#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        long long e = 0;
        long long c = 0;
        for(int i=0; i<n; i++){
            if(a[i]>0){
                e += a[i];
            } else{
                long long neg = -a[i];
                if(e>=neg){
                    e -= neg;
                }else{
                    c += (neg-e);
                    e = 0;
                }
            }
        }
        cout<<c<<endl;
    }
}
// !doubt
