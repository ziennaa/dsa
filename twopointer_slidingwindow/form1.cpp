/*
Form 1: 
solves many problem

Q. Array : [0, 1, 0, 1, 0, 0, 1, 1, 0]
k = 2
flip atmost k positions 0 or 1 (either) to make a longest subarray to
 create of all 1's (or 0's either way)
  [0, 1, 0, 1, flip(1), flip(1), 1, 1, 0]
  ans : 5
  understand this is 2 pointer
  3 parts of problems
  longest : ask
  subarray : what
  of all 1s with atmost k flips : criteria 

  either dealing with : subarrays or max - min (gap)
  longest / shortest / count / sum of length 

  and some monotonic criteria to be satisfied 
  monotonic criteria ??
  [l     r] -> can this be converted to 
  no of zeoroes in [l    r] <= k -> to ensure it is TRUE ??
  [l     r] if it is true here
  then true here too [l     r-1] or [l+1    r]
  no of zeroes in l r <= k
  then l+1 r <= k true right 
  then two pointer straight away
  if this conditon doesnt hold true then probably its not a two pointer solution

*/
/*
code 
for l = 0 to n
fot r l+1 to n 
check (l r)
 ans = (l r)
 -->  o(n2) so will not really pass but a correct solution
 we need linear
 [1 1 1 0 1 1 0 1 end -> after this more than 2 zeroes 0 ]
 start from next end cuz l   r to l+1   r idea 
 weherver the last end / r was 
 2 nested loop -> brute force not work 
 --- so not this 
 not work here
 */

 // TEMPLATE || how to apply two pointers || code 
 //  0  1  2  3  4  5  6  7  8
 // [0, 1, 0, 1, 0, 0, 1, 1, 0] k=2
 /*
 start at 0
 start eating 
 tail and head maintain
 after head = 3 u cant eat more
 -- > -- > -- > -- > -- >
 once done with 0 to 3
 move tail one step forward 
 next iteration -> try to eat again 
 after head eat again and see 
 then again move tail one step forward
 and simillary do with head
  -> as long as you can eat keep moving forward
 */
// 3 parts 
/* 

loop : (tail < N)
1. eat as many as you can ( inserting )
2. update answer
3. move tail 1 step forward ( removing )

*/
/*

we've to check 
maintain ds of what is there in current window 
and can quickly check whether we can take next element or not
insert next element 

and when tail moves forward it shouldn remove the previous element 

in the above q 
no of zeroes will give us the answer
and value of k 
can i take next element or not 
ds here is countofzero 


every problem 
1. decide ds
2. decide ans
3. loop 
*/
/*
below is how we're slowing thinking to implmenet the code
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    // ds // third thing
    // ans // 2nd thing
    int ans = 0;
    // tp stuff - 1st thing
    int tail 0;
    int head = -1;
    // why head = -1 ??
    while (tail < n){
        // step1 : keep eating as many as possible
        while(head + 1 < n && (/*we can eat thr next element*/ //)){ 
           // head++; // go forward */
            // eat (arr[head])
        //}
        // step2 : update the answer
  //      ans = // update answer 
        // step3: move tail one step forward
  //      tail++;
   // }
//} 
#include <bits/stdc++.h>
    using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // ds // third thing
    int countzero=0;
    // ans // 2nd thing
    int ans = 0;
    // tp stuff - 1st thing
    int tail = 0;
    int head = -1;
    // why head = -1 ??
    // set to 0 length as start
    while (tail < n)
    {
        // step1 : keep eating as many as possible
        while (head + 1 < n && (countzero < k || countzero == k && arr[head + 1] == 1 /*we can eat thr next element*/))
        {
            head++; // go forward
            // eat (arr[head])
            if(arr[head] == 0) countzero++;
        }
        // step2 : update the answer [DONE!!!]
        // [    tail   head    ]
        // 0   1 2 3     4 5
        // length : head-tail +1
        ans = max(ans, head-tail+1); // update answer
        // step3: move tail one step forward
        // tail is before head 
        if(tail <= head) {
            if(arr[tail] == 0) countzero--;
            tail++;
        }else{
            // tail is ahead  
            // what is this ??!!
            tail++;
            head = tail-1;
        }
        //tail++; 
    }
    cout<<ans<<"\n";
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
/*we can eat thr next element*/
// how to decide this
// array [countzero ] -> some ele (0 or 1)
// how do you decide whether to take next element or not ?
// countzero <= k ? but if next next is 0 then it is not valid not
// newcoint = countzzero
// if next el is zero 
// new count
// newcount <=k
// after eating the <= k condition should hold ! 
// new count of 0 <= k not current why ??
// countzero < k  || countzero == k && arr[head+1] == 1 
// see if countzero < k then we can always eat whether 0 or 1
// but to see next element we can only eat if next element is 1
// soo it will be countzero == k && arr[head+1] == k

// will this code work ?
// is it optimised ??
// whatre the q marks above ??


//       [0 1 0 1 0 0 1 1 0]
// head   tail 
// head will try to eat 0 right

// k = 0
// [ 0 0 0 1 ]
//   tail and head at 0 no
// we cant take 1 element to
// try to eat single element
// so head = -1
// head-tail +1 => -1+0+1 => 0
// this signifies 0 length : head = -1

// 0 not inside so move tail 1 step forward 
// so we're in else condition now
// head < tail
// so now if u do this
// tail-1-tail+1 = 0
// head = tail -1 setting my length as 0 
// if zero length
// move tail forward and reset to 0 length


// TIME COMPLEXITY OF THIS CODE
// O(n)
// 2 while why O(n) ??
// for every pointer -> we're doing O(1)
// head and tail traversing whole array once
// O(N (H+a+T)) 
// H -> while head+1 part O(1)
// ans update is a O(1) 
// T ++ -> O(1)


// This template can solve every problem of two pointer 