#include <iostream>
using namespace std;
int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a+b-c==d){
        cout<<"YES"<<endl;
    }
    else if(a-b+c==d){
        cout<<"YES"<<endl;
    }
    else if(a*b+c==d){
        cout<<"YES"<<endl;
    }
    else if(a+b*c==d){
        cout<<"YES"<<endl;
    }
    else if(a*b-c==d){
        cout<<"YES"<<endl;
    }
    else if(a-b*c==d){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

//other : covering all the edge cases
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y, z, k;
    cin >> x >> y >> z >> k;

    if (x + y + z == k) cout << "YES\n";
    else if (x + y - z == k) cout << "YES\n";
    else if (x + y * z == k) cout << "YES\n";
    else if (x - y + z == k) cout << "YES\n";
    else if (x - y - z == k) cout << "YES\n";
    else if (x - y * z == k) cout << "YES\n";
    else if (x * y + z == k) cout << "YES\n";
    else if (x * y - z == k) cout << "YES\n";
    else if (x * y * z == k) cout << "YES\n";
    else if ((x + y) + z == k) cout << "YES\n";
    else if (x + (y + z) == k) cout << "YES\n";
    else if ((x + y) - z == k) cout << "YES\n";
    else if (x + (y - z) == k) cout << "YES\n";
    else if ((x - y) + z == k) cout << "YES\n";
    else if (x - (y + z) == k) cout << "YES\n";
    else if ((x - y) - z == k) cout << "YES\n";
    else if (x - (y - z) == k) cout << "YES\n";
    else if ((x + y) * z == k) cout << "YES\n";
    else if (x + (y * z) == k) cout << "YES\n";
    else if ((x * y) + z == k) cout << "YES\n";
    else if (x * (y + z) == k) cout << "YES\n";
    else if ((x - y) * z == k) cout << "YES\n";
    else if (x - (y * z) == k) cout << "YES\n";
    else if ((x * y) - z == k) cout << "YES\n";
    else if (x * (y - z) == k) cout << "YES\n";
    else if ((x * y) * z == k) cout << "YES\n";
    else if (x * (y * z) == k) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
