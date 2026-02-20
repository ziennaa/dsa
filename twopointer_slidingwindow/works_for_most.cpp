// Q. number of subarrays having number of distinct elements <= k
/*
[ 1 2 1 3 ] k=
 [1 2 1 3] total no of subarrays is 8

 answer : 8

 1
 2
 1
 3
 1 2
 1 2 1
 2 1
 1 3

*/
// this exact template to follow for most or simillar 2 pointer problem 
// wherever ive added changeable only that is to be changed
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int tail = 0;
    int head = -1;
    map<int, int> mp; // data structure for the problem to store : this is changeable
    int distinct = 0;  // to store values this is too changeable
    int ans = 0;;
    while(tail < n){
        while(head+1 < n && (distinct < k || mp[a[head+1]] >= 1)){
            // (distinct <= k || mp[a[head+1]] >= 1 changeable 
            // also here why is it distinct < k and not <= k ??
            // what's our condition ?
            // keep increasing head as long as adding the next element will
            // still keep the window valid 
            // will this work ? x = a[head+1] added will distinct stay <= k
            // mp[x] > 0 : x already exists -> distinct doesnt increase
            // if mp[x] == 0 : x is new -> distinct increases by one
            // so adding allowed when we still have room for new distinct < k
            // x is not new mp[x] > 0
            head++;
            if(mp[a[head]] == 0){
                distinct++;
            }
            //distinct++;
            mp[a[head]]++;
        }
        ans += (head - tail+1); // changeable depending upon what needs to be done
        if(tail > head){
            tail++;
            head = tail-1;
        }else{
            mp[a[tail]]--;
            if(mp[a[tail]] == 0){
                distinct--;
            }
            tail++;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

// Time Complexity : O(n logn)
// space complexity : O(k)
/*
How did we get O(nlogn) ?
tail : moves forward from 0 to n-1 : at most n increments
head : moves forward from -1 to n-1 : at most n increments 

in the case of brute force 
for every tail u set head = tail
move head forward 
and head restarts n times

O(n) window updates total 
but each update has map cost : O(logn)

hence -> o(nlogn)
*/

// the above code wont work when we have a condition of a[i] < 10^6 so yeahh
// so instead of going with map which simply increases our cost
// we go with array i.e frequency array to keep track of it