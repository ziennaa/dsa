#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum = 0;
        for(int i=1; i<n; i++){
            if(i%3==0 || i%5==0){
                sum += i;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}

/* failed at some tesr case due to tc */
/* no of multiple below n is given floor((n-1)/m) */
/* in order to get sum of those number of multiples you would do m*th*(th+1)/2*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum = 0;
        int th = floor((n-1)/3);
        int fi = floor((n-1)/5);
        int lcm = floor((n-1)/15);
        sum = 3*th*(th+1)/2 + 5*fi*(fi+1)/2 - 15*lcm*(lcm+1)/2;
        cout<<sum<<"\n";
    }
    return 0;
}
