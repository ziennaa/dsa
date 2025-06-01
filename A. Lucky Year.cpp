#include <bits/stdc++.h>
using namespace std;
bool lucky(int n){
    int l=0;
    int count=0;
    while(n>0){
        int d=n%10;
        if(d>0){
            count++;
        }
        n = n/10;
    }
    if(count==1){
        return true;
    }else{
        return false;
    }
}
int main(){
    long long n;
    cin>>n;
    long long temp=n;
    while(true){
        n++;
        if(lucky(n)){
            cout<<n-temp<<endl;
            break;
        }else{
            continue;
        }
    }
}

// TLE ERROR IN ABOVE ONE!!!! (1000ms+)?

//optimised 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int msd=n;
    int count=0;
    while(msd>=10){
        msd/=10;
        count++;
    }
    int lucky=(msd+1)*pow(10, count);
    cout<<lucky-n<<endl;
}


