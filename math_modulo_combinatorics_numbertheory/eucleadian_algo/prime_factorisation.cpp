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
// why i*i here?
// if number x has any composite structure left it must have factor <= root x
// assuming x = a*b
// a > root x and b > root x
// a*b > x
//  not possible
// so if x is composite at least one factor must be <= root x
// so basically i*i till x 
// checking all possible small factors
// if none divides x then x cannot be composite
//“A composite number cannot be made from two numbers that are both bigger than its square root.”
