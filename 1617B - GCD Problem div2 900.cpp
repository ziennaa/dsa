+#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        int c = 1;
        int sum = n-c;
        int a = 1, b=sum-a;
        while(__gcd(a,b)!=c || a==c || b==c || a==b){
            a++;
            b = sum - a;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
}
/*
ab+c=n
  and gcd of a and b is c
so what we can do is
  we can set up c to 1
  c=1
  now a+b=n-c or a+b=n-1
  and gcd of a and b =1 
  now when is it one
when they both are coprime
so what we do is
  set up c to 1 and sum to n-c
  then set up a to 1 starting point and b to sum-a
  then make loop that till gcd of a and b is not equal c or a==c ==b (since theyve to be distinct)
increase a
and do b=sum-a; which basically says the condition a+b+c=n*/
