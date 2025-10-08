#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int l, r;
  cin>>l>>r;
  if(r-l>=2019){
    cout<<0<<"\n";
    return 0;
  }
  int ans = 2019;
  for(int i=l; i<=r; i++){
    for(int j=i+1; j<=r; j++){
      int temp = ((i%2019)*(j%2019))%2019;
      ans = min(ans, temp);
    }
  }
  cout<<ans<<"\n";
}

/*
why this is ac and not causing TLE?
cuz when r-l>2019 ans is 0
so we're just doing brute force for r-l<2019
and o(n2) so around 2*10^6
which works
*/
