#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int l=0;
    int u=0;
    for(char c : s){
        if(c>=97 && c<=122){
            l++;
        }
        else if (c>=65 && c<=90)
        {
            u++;
            /* code */
        }
    }
    if(l>=u){
        for(char &k : s){
            k = tolower(k);
        }
        cout<<s<<endl;
    }
    else if(u>l){
        for(char &p : s){
            p = toupper(p);
        }
        cout<<s<<endl;
    }
}
