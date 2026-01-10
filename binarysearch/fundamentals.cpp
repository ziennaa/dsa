/*
Binaey Search Fundamentals
ideas: low mid high monotonocity
-> how to recognise and solve ?
recognise
1. sorted
2. min/max some optimal sol
3. optimal -> maxima/minima
4. optimisation
5. N <= 10^5
solve
1. designing
2. check
3. application form
4. problem
*/
/*
[1, 5, 10, 15, 19, 21, 35, 100]
find 17 ? doesn't exists
find 35 ? exists
can be found -
linear solution : o(n)  -> brute force and so can be ineffecient
binary searcch : o(logn)
why logn  -> goes from N, N/2, N/4, N/8
*/

// Q1. find index of first 1
// V.IMP can be applied to every question!
// TEMPLATE
// [0, 0, 0, 0, 0, 0, 1, 1, 1]
// [0, 1, 2, 3, 4, 5, 6, 7, 8] indexes
// sorted
// 1. binary search 
// low = 0
// high = 8
// low and high are search space
// if array had been [0,0,1,1,1,1,1,1,1]
// indexes -> [0,1,2,3,4,5,6,7,8]
// is ans[4] = 1 mid -> included or excluded ?
// search space should be strictly decreasing
// never include again if searched
// ans var set up that stores best possible ans till now
// mid = low+(high-low)/2 better than low+high/2 as it avoids overflow
// code
/*
while(low<=high){
    int mid = low+(high-low)/2;
    if(arr[mid] == 1){
        ans = mid;
        high = mid-1;
    }else{
        low = mid+1;
    }
}
return ans;
*/
// above is the template and can be applied to every problem
