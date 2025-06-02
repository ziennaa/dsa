#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin>>n;
        int a[n];
        int b[100]={0};
        for(int i=0; i<n; i++){
            cin>>a[i];
            b[a[i]]++;
        }
        int mexa=0;
        int mexb=0;
        while(mexa<100 && b[mexa]>0){
            mexa++;
        }
        while(mexb<100 && b[mexb]>1){
            mexb++;
        }
        cout<<mexa+mexb<<endl;
    }
    return 0;
}
