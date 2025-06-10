#include <bits/stdc++.h>
using namespace std;
int maxCandiesEaten(int N, long long K, vector<long long>& A) {
    sort(A.begin(), A.end()); 
    int time = 0, count = 0;
    for (int i = 0; i<N; i++) {
        if (A[i] - time >= K) {
            count++;
            time++// 1 candy in 1 sec
        } else {
            count = count;
        }
    }
    return count;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long K;
        cin >> N >> K;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << maxCandiesEaten(N, K, A) << endl;
    }
    return 0;
}
