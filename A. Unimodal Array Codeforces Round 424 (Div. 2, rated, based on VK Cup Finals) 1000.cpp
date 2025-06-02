#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int i=1;
    while(i<n && a[i]>a[i-1]){
        i++;
    }
    while(i<n && a[i]==a[i-1]){
        i++;
    }
    while(i<n && a[i]<a[i-1]){
        i++;
    }
    if(i==n){
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }
}
