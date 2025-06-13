/*Given an array nums and a number k, you can increase any elements at most k times in total, to make some numbers equal.
You need to return the maximum frequency of any number you can achieve.*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int a[n];
        for(int i = 0; i < n; i++) {
            a[i] = nums[i];
        }
        int maxx=0;
        for(int i=0; i<n; i++){
            if(maxx<a[i]){
                maxx=a[i];
            }
        }
        int sum=0;
        for(int i=0; i<n; i++){
            int y= maxx-a[i];
            int h=a[i];
            if(y<=k){
                sum += y;
                a[i] = maxx;
            }
        }
        int hash[100000]={0};
        for(int i=0; i<n; i++){
            hash[a[i]]++;
        }
        return hash[maxx];
    }
};

// pnly passed few test cases then stopped

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        long long l=0, r=0;
        long long res=0, total=0;
        while(r<n){
            total += nums[r];
            while(nums[r]*(r-l+1)>total+k){
                total -= nums[l];
                l+=1;
            }
            res = max(res, r-l+1);
            r += 1;
        }
        return res;
    }
};

/*
in the second one first we sorted the array
we made a left pointer and a right pointer 
basically we're making a sliding widnow
so basically 
res and total
so it is 
expand while
  num[r].windowlength<toal +k
  why +k? cuz its our budget ok
then why num[r*window length
this basically tells us the numbers which we can make equal till num[r] or we're trying to make it equal 
and toal is the length +k which we can implemt*/

/*
explanation chatgpttt
Let’s first understand why the second one is correct:

cpp
Copy
Edit
while (nums[r] * window_size > total + k) {
    shrink from left
}
This is saying:

“Can we make all numbers in the current window equal to nums[r] by only increasing smaller elements using at most k operations?”

window_size = (r - l + 1)

nums[r] * window_size: the target sum if all elements were nums[r]

total: the actual sum of current window

So nums[r]*window_size - total is the cost to make them all equal to nums[r]

If it's more than k, we can't afford it, so we shrink the window.

This method is efficient and correct — it’s greedy and ensures the window always fits within budget k.

*/



//// WHY FIRST ONE WRONG??
/*
Greedy But Not Optimal:
You picked the largest number in the array and tried to raise everything else up to that.
But what if that’s too expensive?

Example:

ini
Copy
Edit
nums = [1, 2, 4], k = 5
Raising everything to 4 costs:

4 - 1 = 3

4 - 2 = 2
➜ Total = 5 works!

But in:

ini
Copy
Edit
nums = [1, 2, 10], k = 5
Trying to raise everything to 10 costs:

10 - 1 = 9

10 - 2 = 8
➜ Total = 17  too much!
*/
/*


Your Version (1st code)	              Sliding Window Version (2nd code)
Always targets max value	            Tries every number as a target
Greedy, not always optimal	           Greedy with moving window, optimal
No sorting used	                      Sorted input for easier control
Fails on hard cases	                   Efficient, passes all cases 


*/
