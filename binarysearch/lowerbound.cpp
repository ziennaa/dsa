/*
lowerbound
arr : [2, 3, 5, 7,7,7,17,17,21]
idx : [0, 1, 2, 3,4,5.6,7,8]
low = 0
high = 8
mid  = 4
stl cpp function : 
lower_bound(arr, arr+n, 10) = x
check : is arr[i] >= x if yes update ans else no
check: [0, 0, 0, 0, 0, 0, 1, 1, 1]
*/

#include <bits/stdc++.h>
using namespace std;
int n, x;
int arr[100100];
int checker(int mid, int x){
    if(arr[mid]>=x) return 1;
    else return 0;
}
int main(){
    cin>>n;
    cin>>x;
    for(int i=0; i<n; i++) cin>>arr[i];
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(checker(mid, x)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans<<"\n";
}