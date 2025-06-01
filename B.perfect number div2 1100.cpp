#include <bits/stdc++.h>
using namespace std; 
bool perfect(int n){
    int sum = 0;
    while(n>0){
        int digit = n%10;
        sum += digit;
        n /= 10;
    }
    if(sum==10){
        return true;
    }else{
        return false;
    }
}
    
int main(){
    int k;
    cin>>k; 
    int count=0;
    int number=18;
    while(count<k){
        number++;
        if(perfect(number)){
            count++;
        }
    }
    cout<<number<<endl;
    /*
    if(k==1){
        cout<<19<<endl;
    }else if(k==2){
        cout<<28<<endl;
    }
    else{
        cout<<19+(9*(k-1));
    }*/

//perfect number
