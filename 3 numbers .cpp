#include <bits/stdc++.h>
using namespace std;
int main(){
    int k, s;
    cin>>k>>s;
    cout<<k+s<<endl;
    int count=0;
    for(int i=0; i<=k; i++){
        for(int j=0; j<=k; j++){
            int z = s - i - j;
            if(z>=0 and z<=k){
                count++;
            }
        }
    }
    cout<<count<<endl;
}
//easy problem
// direct sol
