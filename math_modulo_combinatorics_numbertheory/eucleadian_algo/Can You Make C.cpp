/*
Description
Let us see the following equation,

A
x
+
B
y
=
C
Ax+By=C

Given three positive integers 
A
A, 
B
B and 
C
C.

You have to determine whether there exists at least one solution for some integer values of x and y where $x, y$ may be negative or non-negative integers.
  */
//All values of Ax + By are multiples of gcd(A, B)
#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int k = gcd(a, b);
        if(c%k == 0){
            cout<<"Yes"<<"\n";
        }else{
            cout<<"No"<<"\n";
        }
    }
}
