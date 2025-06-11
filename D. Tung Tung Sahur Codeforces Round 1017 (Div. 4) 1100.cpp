#include <bits/stdc++.h>
using namespace std;
void solve() {
    string p, s; // accepted p and s
    cin >> p >> s;
    int i = 0, j = 0; // we created pointers for p string i and s string j
    while (i < p.size() && j < s.size()) { // if both in size
        if (p[i] != s[j]) { // and initial chars not matching then out
            cout << "NO\n";
            return;
        }
        int count_p = 0; // count of p
        char current = p[i];  // and current char
        while (i < p.size() && p[i] == current) { // here we're checking how many times the current character appears in p till current ok
            count_p++;
            i++;
        }
        int count_s = 0;
        while (j < s.size() && s[j] == current) { // simillar for j
            count_s++;
            j++;
        }
        if (count_s < count_p || count_s > 2 * count_p) { // if this condition true then out cuz // s>p(min) || s<2*p (max)
            cout << "NO\n";
            return;
        }
    } // now move to r from l or l from r
    if (i == p.size() && j == s.size()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
