#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x, y, z;
    cin>>x>>y>>z;
    if(x%z==0 && y%z==0) cout<<"Both"<<endl;
    if(x%z==0 && y%z!=0) cout<<"Memo"<<endl;
    if(x%z!=0 && y%z==0) cout<<"Momo"<<endl;
    if(x%z!=0 && y%z!=0) cout<<"No One"<<endl;
}

    
