#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<int> a;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            a.insert(num);
        }
        int total=0;
        while(!a.empty()){
            int m = *a.rbegin();
            a.erase(m);
            if(m%2==0){
                total++;
                a.insert(m/2);
            }
        }
        cout<<total<<endl;
    }
}
