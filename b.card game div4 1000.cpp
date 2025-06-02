#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a1, a2, a3, a4;
        cin>>a1>>a2>>a3>>a4;
        if(a1<=a3 && a1<=a4 && a2<=a3 && a2<=a4){
            cout<<0<<endl;
        }else if(a1>a3 && a2>a3 && a1>a4 && a2>a4){
            cout<<4<<endl;
        }else if(a1>a3 && a1>a4 && (a2>a3 || a2>a4)){
            cout<<2<<endl;
        }
        else if(a2>a3 && a2>a4 && (a1>a3 || a1>a4)){
            cout<<2<<endl;
        }else{
            cout<<0<<endl;
        }
    }
}

// wrong answer some case not covered
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int suneetWins = 0;
        if ((a1 >= b1 && a2 > b2) || (a1 > b1 && a2 >= b2)) suneetWins+=2;
        if ((a1 >= b2 && a2 > b1) || (a1 > b2 && a2 >= b1)) suneetWins+=2;
 
        
        cout << suneetWins << "\n";
    }
 
    return 0;
}
