#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(n>100 or m>100){
            cout<<"NO"<<endl;
            continue;
        }
        if(n<1 or m<1){
            cout<<"NO"<<endl;
            continue;
        }
        int count=0;
        for(int i=0; i<n; i++){
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            if(b==c){
                count++;
            }
        }
        if(m%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        if(count>0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
