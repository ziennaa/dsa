#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long temp=n;
        long long last = n%10; 
        long long first = 0;
        while(temp>=10){
            temp /= 10;
        }
        first = temp;
        if(first != 1 || last==9){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
}

// not working for all cses cuz a+b=n also weve to check
 while(x >= 10) {
    int d = x % 10;

    if(flag == 1) {
        // First digit (from right)
        if(d > 8) → "NO" (too large for last digit from 5+5 to 9+9)
        flag = 0;
    } else if(d == 0) → "NO"
    
    x /= 10;
}
if(x == 1) → "YES"
else → "NO"

///

#include <iostream>
using namespace std;
#define ll long long
void solve() {
  ll n; cin >> n;
  n = n - n % 10 + (n % 10 + 1) % 10; 
  while (n > 9) {
    if (n % 10 == 0) {
      cout << "NO\n";
      return;
    }
    n /= 10;
  }
  cout << (n == 1 ? "YES\n" : "NO\n");
}
 
int main() {
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
