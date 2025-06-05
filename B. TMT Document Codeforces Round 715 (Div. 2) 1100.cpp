#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       string s;
       cin>>s;
       int tc=0;
       int m=0;
       for(int i=0; i<n; i++){
            if(s[i]=='T'){
                tc++;
            }else if(s[i]=='M'){
                m++;
            }
       }
       if(tc != 2*m){
         cout<<"NO"<<endl;
         continue;
       }
       int tcx=0;
       int mx=0;
       bool v=true;
       for(int i=0; i<n; i++){
            if(s[i]=='T') tcx++;
            else mx++;
            if(mx>tcx){
                v=false;
                break;
            }
       }
       if(!v){
        cout<<"NO"<<endl;
        continue;
       }
       tcx=0;
       mx=0;
       v = true;
       for(int i=n-1; i>=0; --i){
            if(s[i]=='T') tcx++;
            else mx++;
            if(mx>tcx){
                v=false;
                break;
            }
       }
        cout<<(v ? "YES\n" : "NO\n");    
    }
}
