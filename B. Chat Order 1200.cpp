#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    stack<string> chat;
    for(int i=0; i<n; i++){
        string name;
        cin>>name;
        chat.push(name);
    }
    set<string> printed;
    while(!chat.empty()){
        string name = chat.top();
        chat.pop();
        if(printed.find(name)==printed.end()){
            cout<<name<<endl;
            printed.insert(name);
        }
    }
}


// optimize!!!!
