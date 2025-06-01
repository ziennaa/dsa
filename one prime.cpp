#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    bool isprime = true;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            isprime = false;
            break;
        }
    }
    if(n==2 || (n>2 && isprime)) cout<<"YES\n";
    else cout<<"NO\n";
}

//very basic code
