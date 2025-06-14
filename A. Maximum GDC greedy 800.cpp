#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        int maxx=0;
        int result=0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                result = __gcd(i, j);
                maxx = max(maxx, result);
            }
        }
        cout<<maxx<<endl;
    }
}
// correct but tle
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        cout<<n/2<<endl;
    }
}
/*
why this analogy works?
1<=a<b<=n
both a and b would be divisible by g
and g is a number between 1 to n
smallest possible
a=g*x
b=g*y
smallest possible value of x and y : 1 and 2
so its like gcd(g, 2g) 
<=n 
now 
2g<n
g<n/2
therefore n/2
*/
