/*
2D matrix Arr of dimensions : n*m
where each cell contains a numerical value
objective: answer series of queries related to the sum of values within specified rectangles
Queries:
There are queries of the form ?LRUD 
L left -> leftmost coloumn index
R Right -> rightmost column index
U Up -> the topmost row index
D Down -> the bottommost row index
topmost corner being U,L
bottommost corner being D, R

objective: for each query calculate and output the sum of values within
specified rectangle
i.e sum of values for cells with indices i, j
U <= i<= D
L <= j <= R
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
const int MAXN = 1000; // assuming max size of 2d array
int Arr[MAXN][MAXN];
int P[MAXN][MAXN];
void compute_prefixsum(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            P[i][j] = Arr[i][j];
            if(i>0) P[i][j] += P[i-1][j];
            if(j>0) P[i][j] += P[i][j-1];
            if(i>0 && j>0) P[i][j] -= P[i-1][j-1];
        }
    }
}
int query_rectangle_sum(int U, int L, int D, int R){
    int ans = P[D][R];
    if(L > 0) ans -= P[D][L-1];
    if(U > 0) ans -= P[U-1][R];
    if(U>0 && L>0) ans+=P[U-1][L-1];
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cout<<"enter number of rows and cols : ";
    cin>>n>>m;
    cout<<"enter the values of 2d array: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>Arr[i][j];
        }
    }
    compute_prefixsum(n, m);
    int Q;
    cout<<"enter number of queries: ";
    cin>>Q;
    for(int i=0; i<Q; i++){
        int U, L, D, R;
        //cin>>U>>L>>D>>R;
        cout<<"Enter query "<<q+1<<" (UDLR) ";
        cin>>U>>L>>D>>R;
        int result = query_rectangle_sum(U, L, D, R);
        cout<<"sum of values in rectangle: "<<result<<"\n";
    }
}