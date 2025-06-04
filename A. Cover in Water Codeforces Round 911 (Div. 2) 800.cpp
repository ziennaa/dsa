#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int flag=0;
    int current_count=0;
    int count=0;
    for(int i=0; i<n; i++){
        if(s[i] == '.'){
            current_count++;
        }
        else{
            count+=current_count;
            if(current_count>=3){
                flag=1;
            }
            current_count=0;
        }
    }
    count+=current_count;
    if(current_count>=3){
        flag=1;
    }
    if(flag){
        cout<<2<<endl;
    }else{
        cout<<count<<endl;
    }
}
int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
