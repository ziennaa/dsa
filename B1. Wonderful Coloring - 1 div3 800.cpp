#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        map<char, int> freq;
        for(char c: s){
            freq[c]++;
        }
        int count=0;
        for(auto [ch, cnt]: freq){
            count +=  min(cnt, 2);
        }
        cout<<count/2<<endl;
    }
}
