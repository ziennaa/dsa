#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int sum=0;
        int minimum=*min_element(a.begin(), a.end());
        sort(a.begin(), a.end());
        for(int i : a){
            if(i>minimum){
                sum += (i-minimum);
            }
        }
        cout<<sum<<endl;
    }
}
