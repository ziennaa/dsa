/*
Painter Partition
Very Important Sweep pattern
N walls K painters
arr -> [1 3 8 7 2 5]
say k = 2
then basically in these kind of questions you've to minimise the maximum
so maximum subarray you can get as
1 25
4 22
12 14
19 7
21 5
if i minimise the maximum
i got 12 14 as my answer
this can be done using binary search
search space will be
0 to summation of the array
and we will set a poiner for k to see if its equal to k or not
and then do check(mid) here
basically question is :
can we complete in <= mid(sec)
array <= k partitions
so if i do dry run its like this
say mid is 12
so
1+3+ 8 = 12
stop
new
7+2+5 = 14
TC : O(log|search space|.check)
O(log(summation of Ai)*N)


We binary search the minimum possible maximum workload X.
For a candidate X, we greedily assign boards left-to-right to
the current painter until adding the next board would exceed X, then we start a new painter.
If we need more than k painters, X is too small;
otherwise it’s feasible. This predicate is monotonic, so binary search works.


Sweep / partition check: you’re distributing a sequence into groups (contiguous usually) under a limit mid.
*/

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100100];
int check(int mid){
    int last_painter = 0;
    int people = 0;
    for(int i=0; i<n; i++){
        if(last_painter >= arr[i]){
            last_painter -=  arr[i];
        }else{
            people++;
            if(people > k) return 0;
            last_painter = mid;
            if(last_painter >= arr[i]){
                last_painter -= arr[i];
            }else{
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    cin>>n>>k;
    int sum = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    int low = 0;
    int high = sum;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid) == 1){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans<<"\n";
}
