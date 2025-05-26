// first way
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y, z;
    cin>>x>>y>>z;
    int m = std::max({x,y,z});
    int n = std::min({x,y,z});
    cout<<n<<" "<<m<<endl;
}
// other
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y, z;
    cin>>x>>y>>z;
    int m = x;
    int n = x;
    if(y>m) m = y;
    if(z>m) m = z;
    if(y<n) n = y;
    if(z<n) n = z;
    cout<<n<<" "<<m<<endl;
}

