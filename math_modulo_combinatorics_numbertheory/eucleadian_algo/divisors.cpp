#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> divisors(int x){
    vector<int> ans;
    for(int i=1; i*i<=x; i++){
        if(x%i == 0){
            ans.push_back(i);
            if(i*i!=x){
                ans.push_back(x/i);
            }
        }
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> p = divisors(n);
    for(auto it: p){
        cout<<it<<"\n";
    }
}
// if i divides x 
// (x/i) also divides x
// assuming x = 36
/*
i       x/i
1       36
2       18
3       12
4       9
6       6
*/
// why're we not going till x?
// TC in that case would be O(X) too slow for big numbers
// i = sqrt(x) you stop discovering new divisor pairs
// why i*i
// i = 36
// i = 7 => 7*7 => 49 > 36 so we stop all divisor pair already found
// push ans.push_back(i)
// push ans.push_back(x/i)
// if i == x/i then don't push twice!
/*
Loop only till √x

    Collect both at the same time

        Avoid duplicates at √x
*/
