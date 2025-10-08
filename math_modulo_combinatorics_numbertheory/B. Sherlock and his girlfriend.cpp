#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isPrime(int x){
    if(x<2) return false;
    for(int i=2; i*i<=x; i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  //vector<int> a(n);
  //for(int i=1; i<=n i++) a[i] = i+1; 
  //if(n==1 || n==2){ cout<<1<<"\n";
  if(n==1){
    cout<<1<<"\n";
    cout<<1<<"\n";
    return 0;
  }
  if(n==2){
    cout<<1<<"\n";
    cout<<1<<" "<<1<<"\n";
    return 0;
  }
  cout<<2<<"\n";
  for(int i=2; i<=n+1; i++){
    if(isPrime(i)) cout<<1<<" ";
    else cout<<2<<" ";
  }
  cout<<"\n";
}
