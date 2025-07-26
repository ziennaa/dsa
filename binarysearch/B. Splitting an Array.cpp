#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[100005]; // declare globally for access in all functions
bool is_valid(int x){
    long long cur_Sum = 0;
    int seg = 1;
    int left = 0;
    int right = n;
    int max_allowed_sum = x;
    for(int i=left; i<right; i++){
        if(a[i]>x) return false;
        if(cur_Sum + a[i] <=x ){
            cur_Sum += a[i];
        }else{
            seg++;
            cur_Sum = a[i];
        }
    }
    return seg <= k;
}
    //if(cur_Sum <= x && seg<=k){
    //    return true;
    //}else{
    //    return false;
//}//
//    ////while(cur_Sum <= x && seg<=k){}
//}//
int main(){
    //int n, k;
    cin>>n>>k;
    //int a[n];
    long long low=0;
    int high=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        low = max(low, a[i]);  
        high += a[i];
    }
    //int low=0;
    //int high=n-1;
    long long ans = high;
    while(low<=high){
        long long mid = (low+high)/2;
        if(is_valid(mid)){
            ans=mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}


/*
B. Splitting an Array
time limit per test1 second
memory limit per test256 megabytes
Given an array of n
 positive integers. Your task is to divide it into k
 segments so that the maximum sum on the segment is the minimum possible.

Input
The first line contains integers n
 and k
 (1≤k≤n≤105
). The second line contains the elements of the array ai
 (1≤ai≤109
).

Output
Print one number, the minimum possible maximum sum on the segment.

Example
InputCopy
10 4
1 3 2 4 10 8 4 2 5 3
OutputCopy
12*/

/*
partition array, binary search on array
an integer k, need to divide into k or fewer contigious statements
minimise the maximum sum and each segment must be contigious */

/* 
goal :
minimise the maximum segemnt sum after splitting into <= k contigious part*/
/*
the minimum possible max segment lies between
low = max element of array
no segment can be smaller than biggest element

high = sum of all elements
largest possible value for max segment sum 
performing binary search on
[low, high]
can i split array into k or fewer segments such that each segment <= mid*/
