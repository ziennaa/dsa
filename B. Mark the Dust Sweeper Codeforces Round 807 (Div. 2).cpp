#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        long long count=0;
        long long sum = 0;
        bool flag = false;
        for(int i=1; i<=n-1; i++){
            sum+=a[i];
            if(a[i]>0){
                flag=true;
            }
            if(a[i] == 0 && flag == true){
                count++;
            }
        }
        cout<<sum+count<<endl;
    }
    return 0;
}
