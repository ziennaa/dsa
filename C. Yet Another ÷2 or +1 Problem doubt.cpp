// error and wrong
#include <bits/stdc++.h>
using namespace std;
bool pal(string s){
    string m=s;
    reverse(m.begin(), m.end());
    if(m==s){
        return true;
    }else{
        return false;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        string news="";
        string bs="";
        bool p=false;
        while(k--){
            if(pal(s)){
                s += s[0]; // add last  not first dude
                p=true;
            }else{
                for(int i=0; i<s.length()/2; i++){
                    s += s[i]; // youre adding first half to whole s which is wrong you need only half string
                    p=false;
                }
            }
        }
        if(p){
            cout<<s<<endl;
        }else{
            cout<<s<<endl;
        }
    }
}

///new code but tle here 
#include <bits/stdc++.h>
using namespace std;
bool pal(string s){
    string m=s;
    reverse(m.begin(), m.end());
    if(m==s){
        return true;
    }else{
        return false;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        while(k--){
            if(pal(s)){
                s += s.back(); // or s[0]
            }else{
                s = s.substr(0, s.length()/2);
            }
        }
        cout<<s<<endl;
    }
}


