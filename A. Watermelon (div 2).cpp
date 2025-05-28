#include <bits/stdc++.h>
using namespace std;

int main() {
    int w;
    cin >> w;

    if (w % 2 == 0 && w >= 4)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

// complicated it by thinking smallest is 2
// logic is : w first of all should be divisible by 2 in order for sum of 2 numbers be 2 
// and smallest sum of even number is 4
// that's why it should be equal or greater than 4
