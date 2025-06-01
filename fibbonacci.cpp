#include <bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return  fib(n-1) + fib(n-2);
}
int main(){
    long long n;
    cin>>n;
    cout<<fib(n)<<endl;
}
// above through recursion
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
    }else if(n==2){
        cout<<1<<endl;
    }else{
        int a = 0;
        int b = 1;
        int fib;
        for(int i=3; i<=n; i++){
            fib = a+b;
            a = b;
            b = fib;
        }
        cout<<b<<endl;
    }
}
// loop

#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin>>N;
    long long m;
    long long c=0; //represneting fib(1)
    long long d=1; // reprenting fib(2)
    if(N==1){
        cout<<0;
    }
    else if(N==2){
        cout<<1;
    }
    else{
        for(int i=3; i<=N; i++){
            m=c+d;
            c=d;
            d=m;
        }
    cout<<m;
    }
}

/*had to make it long long instead of int int*/
