#include <bits/stdc++.h>
using namespace std;
bool okay(long long n){
    for(int i=2; i<=n; i++){
        if(i%2!=0 && n%i==0){
            return true;
        }
    }
    return false;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if(okay(n)){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }        
    }
}


//TLEEEEE UGHGHGGHHGHGGHGH
/*
Yes, if your function has a loop from 2 to n, then yes — it behaves like a brute-force loop, and can be even slower than a double loop in some cases, depending on what it’s doing inside.*/
/*
This goes from 2 to n, checking if any odd number divides n.

So it’s O(n) time complexity — very, very slow for large n like 10^12.*/


#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if(n&(n-1)){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
}

/*
if 
n & (n-1) condition is true that means the number is not a power of 2
and if a number is a power of 2 then it has no odd divisors otherwise it has 
so why is
n &  n-1 not a power of 2
because any power of2 
has exactly 1 bit set in its bit representation
so nowwww
if n=4 = 100
and say 3 = 11
100 & 011 = 000 no longer power of 2 has  has odd divisors*/
