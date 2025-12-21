// segmented sieve
/*Description
Find all prime numbers in the range from 
L
L to 
R
R (endpoints inclusive). Print them in non-decreasing order.*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;
    for(int i=2; i<=n; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=i*i; j<=n; j+=i){
                isprime[j] = false;
            }
        }
    }
    return primes;
}
vector<int> segmented_seive(int l, int r){
    vector<int> base_primes = sieve(ceil(sqrt(r)));
    vector<bool> isprime(r-l+1, true);
    if(l==1) isprime[0] = false;
    for(auto prime:base_primes){
        int ceil_l_by_p = (l+prime-1)/prime;
        int cur_mul = prime*ceil_l_by_p;
        cur_mul = max(prime*prime, cur_mul);
        while(cur_mul<=r){
            isprime[cur_mul-l] = false;
            cur_mul += prime;
        }
    }
    vector<int> primes_l_to_r;
    for(int i=0; i<r-l+1; i++){
        if(isprime[i]){
            primes_l_to_r.push_back(i+l);
        }
    }
    return primes_l_to_r;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l, r;
    cin>>l>>r;
    vector<int> p = segmented_seive(l, r);
    cout<<p.size()<<"\n";
    for(auto it: p){
        cout<<it<<" ";
    }
}
