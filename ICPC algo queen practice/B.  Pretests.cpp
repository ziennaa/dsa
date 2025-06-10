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
        int zc=0;
        int oc=0;
        for(char c : s){
            if(c=='0'){
                zc++;
            }else{
                oc++;
            }
        }
        int final = (zc*100)/n;
        if(final>25){
            cout<<"Bad"<<endl;
        }else{
            cout<<"Good"<<endl;
        }
    }
}
    
