#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a, b;
        cin>>a>>b;
        long long r = (a*a) - (b*b);
        bool isprime = true;
        for(int i=2; i*i<=r; i++){
            if(r%i==0){
                isprime=false;
                break;
            }
        }
        if(r==2 || (r>2 && isprime)) {
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

//tle way too slow a*a - b*b
//taking too much time for bigger numbers

#include <bits/stdc++.h>
using namespace std;
 
bool isPrime(long long n){
    if(n < 2) return false;
    for(long long i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
 
        if(a - b == 1 && isPrime(a + b)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
