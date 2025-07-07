#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll a, b;
    cin>>a>>b;
    ll l=0;
    ll r=max(a,b)*n;
    while(l<r){
        ll mid=(l+r)/2;
        if (((mid/a)*(mid/b))>=n){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
}


/*
n identical rectangles 
width=a;
height=b;
min size of square that can fit all n rectangles in it
let side be x 
so to find smallest value of x such that all n rectangles of a*b can fit inside x*x
  a*_=x
b*_=x
so x/a * x/b >= n
x=mid and well keep a binary search on this thing*/
