#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    int a, b;
    cin>>a>>b;
    // calculating gc: best TC o(log(min(a,b))
    cout<<"gcd of "<<a<<" and "<<b<<" is "<<gcd(a,b)<<"\n";
    cout<<"lcm of "<<a<<" and "<<b<<" is "<<(a*b)/gcd(a,b)<<"\n";
    int arr[] = {3, 4, 6, 12};
    // finding gcd of an array 
    int ans = arr[0];
    for(int i=1; i<4; i++){
        ans = gcd(ans, arr[i]);
    }
    cout<<"array gcd "<<ans<<"\n";
    return 0;
}
