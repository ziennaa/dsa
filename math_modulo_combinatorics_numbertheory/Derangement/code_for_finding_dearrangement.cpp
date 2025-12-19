#include <bits/stdc++.h>
using namespace std;
long long compute(int n){
  if(n==0) return 1;
  if(n==1) return 0;
  return (n-1)*(compute(n-1)+compute(n-2));
}
int main(){
  int n;
  cin>>n;
  cout<<compute(n)<<endl;
}
// TC: O(2^N) bad or not effecient when N is large
#include <iostream>
using namespace std;

long long der[1000001]; // DP array

void compute_derangements(int N, int MOD) {
    der[1] = 0, der[2] = 1;
    for (int i = 3; i <= N; i++) {
        der[i] = ((i - 1) * (der[i - 1] + der[i - 2])) % MOD;
    }
}

int main() {
    int N, MOD = 1e9 + 7;
    cin >> N;
    compute_derangements(N, MOD);
    cout << der[N] << endl;
    return 0;
}

// TC: O(N) 
// SC: O(N)
