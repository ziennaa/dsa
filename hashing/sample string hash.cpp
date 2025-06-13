#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int hash[256]={0};
    // precomputing
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }
    int q;
    cin>>q;
    // fetching
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
}
// above not working if string has space
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin.ignore(); // clear leftover newline
    getline(cin, s); // read entire line including spaces
    int hash[256]={0};
    // precomputing
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }
    int q;
    cin>>q;
    // fetching
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
}
// this doesnt count the number of spaces
// what we did in above one?
// cin.ignore() to clear leftover newline
// getline(cin, s) to read entire line including spaces


#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin.ignore(); // clear leftover newline
    getline(cin, s); // read entire line including spaces
    int hash[256]={0};
    // precomputing
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }
    int q;
    cin>>q;
    // fetching
    while(q--){
        char c;
        cin.ignore(); // cin.ignore() to clear leftover newline
        cin.get(c); // reads spaces too
        cout<<hash[c]<<endl;
    }
}

// above code also count spaces!!1 how??
