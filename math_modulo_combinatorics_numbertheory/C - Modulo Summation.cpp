#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin>>a[i];
  int sum = 0;
  for(int i=0; i<n; i++) sum += (a[i]-1);
  cout<<sum<<"\n";
}

/*
sum(a[i] - 1)
== sum(a[i]) - n
 above can be done as well
*/
