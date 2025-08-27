#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s); // read the whole URL
    // find start of parameters
    size_t qpos = s.find('?');
    string params = s.substr(qpos + 1); 
    // split by '&'
    stringstream ss(params);
    string token;
    while (getline(ss, token, '&')) {
        size_t eqpos = token.find('=');
        string key = token.substr(0, eqpos);
        string value = token.substr(eqpos + 1);
        cout << key << ": " << value << "\n";
    }
    return 0;
}
