#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    cin>>n>>t;
    string s;
    cin>>s;
    for(int i=0; i<t; i++){
        for(int j=0; j<n; j++){
            if(s[j]=='B' and s[j+1]=='G'){
                swap(s[j], s[j+1]);
                j++;
            }
        }
    }
    cout<<s<<endl;
}

// didnt got it first few times cause never iterated the value of j 
// explanation
/*
Now, j = 1 in the next iteration, but this is the boy (B) you just moved
and now it’s next to a girl again (G). If you don’t skip ahead, this boy 
can swap again immediately, which is not allowed in the real-world process. 
*/
