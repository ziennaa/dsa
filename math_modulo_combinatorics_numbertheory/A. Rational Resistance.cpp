#include <bits/stdc++.h>
using namespace std;
#define int long long
signed  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin>>a>>b;
    int ans=0;
    while(a&&b){
        if(a>b){
            ans+=a/b;// number of series connections
            a%=b; // movr to next step
        }else{
            ans+=b/a; // number of parallel connection
            b%=a;
        }
    }
    cout<<ans<<"\n";
}

/*
basic idea is Eucleadian Algorithm
calc if a>b
gcd of a and b
then a%b, b
else do opposite

ex 10 3
10,3
10>3
7,3
7>3
4/3
4>3
1/3
1<3
1/2
1<2
1/1
steps : 6
since s a and b (1 ≤ a, b ≤ 10^18). 
we can't be perfoming rep subtract till we reach 1 so many times
so we do rep sub i.e basically
a/b
a%b


*/
