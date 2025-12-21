#include <bits/stdc++.h>
using namespace std;
#define int long long
//vector<int> sp;
vector<int> primeFactr(int x, vector<int> &sp)
{
    vector<int> ans;
    while(x>1){
        ans.push_back(sp[x]);
        x /= sp[x];
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> sp(n+1);
        for(int i=2; i<=n; i++){
            sp[i] = i;
        }
        for(int i=2; i<=n; i++){
            if(sp[i] == i) // i is prime // first occurence 
            {
                for(int j=2*i; j<=n; j+=i){
                    if(sp[j] == j) // second occurence 
                    {
                        sp[j] = i;
                    }
                }
            }
        }
        vector<int> b = primeFactr(n, sp);
        for(auto it: b){
            cout<<it<<"\n";
        }
    }
}

// tc : per query is o(logn) i.e primeFacrtr 
// but for whole its o(nloglogn)
// Prime factorization per test case: O(log n)
// Total per test case: O(n log log n)
