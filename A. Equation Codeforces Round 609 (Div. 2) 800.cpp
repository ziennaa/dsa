#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    int limit  = sqrt(n);
    if(n<=1) return false;
    for(int i=2; i<=limit; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int b=4; ;b++){
        int a = b+n;
        if(!prime(a) && !prime(b)){
            cout<<a<<" "<<b<<endl;
            break;
        }
    }
}

// earlier did this below
#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    if(n<=1) return false;
    for(int i=2; i<sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int a = n+1;
    int b = n;
    while(true){
        if(prime(a)==false && prime(b)==false){
            if(a-b==n){
                cout<<a<<" "<<b<<endl;
                break;
            }
        }
        a++;
        b++;
    }
}

// and time limit exceeded
/*
why?
 1. for(int i=2; i < sqrt(n); i++)  wrong loop boundary
This loop doesn’t check divisibility up to and including √n
Why it’s bad: May wrongly return true for composite numbers, causing infinite loop or more iterations
fix: Use i <= sqrt(n)
2. recalculating root n in every iteration : increasing time
3. checking prime(a) and prime(b) for every iteration
4. so set up b=4
5. and a is or always should be a = b+n if a-b =n
6. 2 variables increasing together a++ b++ time taking
therfore tle
