#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    if(t<1 || t>5940) return 0;
    while(t--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int ccount=0;
        int dcount=0;
        int temp=0;
        if(a>b){
            temp=a;
            a=b;
            b=temp;
        }
        for(int i=a; i<=b; i++){
            if(i==c){
                ccount++;
            }
            if(i==d){
                dcount++;
            }
        }
        for(int i=a; i<=b; i++){
            if(dcount>=1 && ccount==0){
                cout<<"YES\n";
                break;
            }
            else if(ccount>=1 && dcount==0){
                cout<<"YES\n";
                break;
            }else{
                cout<<"NO\n";
                break;
            } 
        }
    }
}


//other simpler
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t; // inputing testcases
    for(int i=1; i<=t; i++){
        int f=0;
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a>b) swap(a,b);
        for(int j=b; j>=a; j--){
            if(j==d || j==c){
                f++;
            }
        }  
        if(f==2 || f==0){
            cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }
    }
    
}
