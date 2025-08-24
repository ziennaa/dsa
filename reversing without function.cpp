// Write your code here
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0; i<N; i++) cin>>A[i];
        for(int i=0; i<N/2; i++){
            int temp = A[i];
            A[i] = A[N-1-i];
            A[N-1-i] = temp;
        }
        for(int i=0; i<N; i++){
            cout<<A[i]<<" ";
        }
    }
}
