#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        long long alice = 0;
        long long bob = 0;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for(int i=0; i<n; i++){
            if(a[i]%2==0 && i%2==0){
                alice += a[i];
            }else if(a[i]%2!=0 && i%2!=0){
                bob += a[i];
            }
        }
        if(alice>bob){
            cout<<"Alice\n";
        }else if(bob>alice){
            cout<<"Bob\n";
        }else{
            cout<<"Tie"<<endl;
        }
    }
}
// do descending instead of ascending, weve to maximise the result
