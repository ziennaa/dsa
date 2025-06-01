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
