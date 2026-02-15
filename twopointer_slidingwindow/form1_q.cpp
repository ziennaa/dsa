// find the number of subarrays with no of distinct elements <= k


// subarray 
// l to r # of distinct element <= k 
// l+1 to r # of distinct element <= k
// yes 
// two pointer q simple as that
// uncertain is what ? think of ds what ds 
// given tail and head
// such that distinct <= k

/*check here*/
// insert 
// remove 
// if taken distinct <= k
// set 
// but in set
// 2 3 2 3
// set will contain 2 3

// so we use map 
// we can use array
// 2 -> 3
// 3 -> 2
// works 
// 2 distinct elements
// k is the number of distinct elements
// inc : freq[x] ++ 
// dec : freq[x]--
//
#include <bits/stdc++.h>
using namespace std;
int distinct = 0;
int freq[1000100];
void insert(int x){
    if(freq[x] == 0) distinct++;
    freq[x]++;
}
void remove(int x){
    freq[x]--;
    if(freq[x] == 0) distinct--;
}
void solve(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int ans = 0;
    int tail = 0;
    int head = -1;
    while(tail < n){
        while (head + 1 < n && (distinct < k || ( distinct == k && freq[arr[head+1]] > 0) )){
            // see if distinct reached k no
            // so matlab  jo next element hai voh distinct nahi hai right
            // so isko toh hum daal hi sakte hai us main kya hai
            head++;
            insert(arr[head]);
        }
        ans += head-tail+1; // ??
        // no of subarrays with distict <= k or 2 say
        // [1 2 1 3]
        // no of subarray = is same as length of subarray
        // just a concidence 

        if(tail <= head){
            remove(arr[tail]);
            tail++;
        }else{
            tail++;
            head = tail-1;
        }
        //ans += head-tail+1;
    }
    cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
//n find the sum of length of all sub arrays with distinct <= k
// 5 length 
// count is allso length
// [ a| b | c| d| e ]
// ------------------ len
// __ 1
// _______ 2
// ____________3
// _______________4
// ____________________ 5 len
// sum will be (len*(len+1))/ 2 
// why, i ddinty get it ??  
// tail head
// tail is at n
//  1+ 2 + 3 +4 +5 + ...  l
// l*(l+1)/2

// what if q is distinct element == k 
// or >= k

//   count exaxglty == k
// find <= k 
// and then k-1
/*
atmost(k) - atmost(k-1)
*/
// total 
// <= n
// - k-1 
/*
total subarrays - atmost (k-1)*/

// didnt get this  too ???