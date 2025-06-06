#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
            int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        bool eq = true;
        for(int i=1; i<n; i++){
            if(a[i]!=a[0]){
                eq = false;
                break;
            }  
        }
        if(eq==true){
            cout<<-1<<endl;
        }
        else{
            int beautiful=0;
            int count=0;
            for(int i=2; i<n; i++){
                if(a[i-1]==a[i+1] && a[i-1]!=a[i]){
                    beautiful++;
                    count = i;
                }
            }
            cout<<n-count-1<<endl;
        }
    }
}


// didnt work even on case 1
#include <cstdio>
#include <algorithm>

int main(){

    long t; scanf("%ld", &t);
    while(t--){
        long n; scanf("%ld", &n);
        long ans(n + 7);
        long x; scanf("%ld", &x);
        long pos(-1);

        for(long p = 1; p < n; p++){
            long a; scanf("%ld", &a);
            if(a != x){
                ans = std::min(ans, p - 1 - pos);
                pos = p;
            }
        }
        ans = std::min(ans, n - 1 - pos);
        if(ans >= n){puts("-1");}
        else{printf("%ld\n", ans);}
    }

}

this works idk how
