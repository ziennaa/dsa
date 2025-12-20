#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}
signed main(){
    int n;
    cin>>n;
    if(isPrime(n)) cout<<"yes "<<n<<" is prime \n";
    else cout<<"no "<<n<<" is not prime \n";
    return 0;
}

// TC : O(root n) works effeciently till <10^12
// could've gone till n as generic approach but that's not optimised. 
