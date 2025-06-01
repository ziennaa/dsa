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
        int ee=0; // even no. on even index
        int oo=0; // odd no. on odd index
        int eo=0; // even no. on odd index
        int oe=0; // odd no. on even index
        for(int i=0; i<n; i++){
            if(a[i]%2==0 && i%2==0){
                ee++;
            }
            if(a[i]%2!=0 && i%2!=0){
                oo++;
            }
            if(a[i]%2==0 && i%2!=0){
                eo++;
            }
            if(a[i]%2!=0 && i%2==0){
                oe++;
            }
        }
        if(eo==0 and oe==0){
            cout<<0<<endl;
        }
        else if(oe != eo){
            cout<<-1<<endl;
        }
        else if(oe == eo){
            cout<<oe<<endl;
        }
    } 
}
