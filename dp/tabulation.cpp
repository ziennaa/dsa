#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int prev2 = 0;
  int prev = 1;
  for(int i=2; i<=n; i++){
    int curi = prev+prev2;
    prev2 = prev;
    prev = curi;
  }
  cout<<prev<<"\n";
}

/*
prev and prev2 and curi is saving space
otherwise you coulve used dp[i] = dp[i-1]+dp[i-2]
wouldve resulted same
but SC would O(N)
here its O(1)
  and TC is O(N)*/
