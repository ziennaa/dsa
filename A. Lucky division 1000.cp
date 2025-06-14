#include <bits/stdc++.h>
using namespace std;
bool isLucky(int x) {
    int hash[10] = {0};
    while (x > 0) {
        int d = x % 10;
        hash[d]++;
        x /= 10;
    }
    for (int i = 0; i <= 9; i++) {
        if (i != 4 && i != 7 && hash[i] > 0)
            return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (isLucky(i)) {
            if (n % i == 0) {
                found = true;
                break;
            }
        }
    }
    if (found)
        cout << "YES\n";
    else
        cout << "NO\n";
 
    return 0;
}
