/*
rotated array
arr: [1 3 5 7 9] 
arr: [9 1 3 5 7] rotated(1)
arr: [7 9 1 3 5] 2twice
arr: [5 7 9 1 3] thrice

first thing is can we make it into form of 00111
1 2 3 5 9
9 1 2 3 5
5 9 1 2 3
3 5 9 1 2
wanna make it into
0 0 0 1 1
check function
arr[i] > arr[i+1] 
0 0 1 0 0 no
arr[x] <= arr[0]
1 0 0 1 1
no
arr[x] < arr[0]
0 0 0 1 1 yes
*/
#include <bits/stdc++.h>
using namespace std;
int maunb
