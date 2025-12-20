#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair <int, int>> factorise(int x){
    vector<pair <int, int>> ans;
    for(int i=2; i*i<=x; i++){
        if(x%i==0){
            int count = 0;
            while(x%i==0){
                count++;
                x/=i;
            }
            ans.push_back({i, count});
        }
    }
    if(x>1) ans.push_back({x, 1});
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<pair <int, int>> g = factorise(n);
    for(auto it: g){
        cout<<it.first<<" "<<it.second<<"\n";
    }
}
// TC : O(root N)
// Only one prime factor > sqrt(N) can exist.
// If any prime factor remains after the loop, it must be > N
​
