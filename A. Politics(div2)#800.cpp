#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; // input members and opinions (number)
    cin >> n >> k;
    string t[n]; // Declares an array t of size n to store the opinion strings of all members
    int ans = n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i] != t[0]) {
            ans--;
        }
    }
/*Loops through each member:

Takes their opinion string as input.

If their string is not the same as the first member's string (t[0] is your string), then they are not allowed.

So, reduce ans by 1.

 Only members whose opinion string is exactly equal to yours are kept.*/
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
