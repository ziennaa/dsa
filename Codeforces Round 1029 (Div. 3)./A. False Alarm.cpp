#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        int l=-1;
        int r=-1;
        for(int i=0; i<n; i++){
            if(a[i]==1){
                if(l==-1) l=i;
                r=i;
            }
        }
        if(l==-1){
            cout<<"YES\n";
        }else if(r-l+1<=x){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

// dont think of brute force always  its less effecient too
// here 
/*if all the ones in the array are within a subarray of size x then yes otherwise no
what were actually doing is 
we set up l for left and r for right
l checks and stores the first occurence of 1
and r stores the last occurence of 1
then if array no one then yes obviuously 
if r-l+1<=x i.e all ones are able to ebing cover in x or less then yes otherwise no*/
