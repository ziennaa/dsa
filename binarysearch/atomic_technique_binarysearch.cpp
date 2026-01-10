/*
Atomic / factory check: you’re counting how many independent atomic actions fit into mid time / mid capacity, then summing.
Use it when the system is parallel/independent and the question is:

“Given time X, how many units can we produce/serve/process?”
Question A:

“Does an entity repeatedly produce items over time at a fixed rate?”

YES → Atomic

NO → go next

Question B:

“Am I forced to assign/partition an ordered array into k contiguous parts?”

YES → Sweep

NO → maybe another pattern, but often still atomic if it’s rate-based.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, t;
//vector<int> arr;
int check(int mid, vector<int>& arr){
    int total_product = 0;
    for(int i=0; i<n; i++){
        total_product += mid/arr[i];
        if (total_product >= t) return 1;
    }
    if(total_product >= t) return 1;
    return 0;
}
signed main(){
    cin>>n>>t;
    int max_el = INT_MIN;
    vector<int> arr(n);
    int ans = -1;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        max_el = max(max_el, arr[i]);
    }
    int low = 0;
    int high = t*max_el;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(check(mid, arr) == 1){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans<<"\n";
}