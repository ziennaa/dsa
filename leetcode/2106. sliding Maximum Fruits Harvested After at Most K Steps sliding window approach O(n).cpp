
class Solution{
public: 
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k){
        int left = 0;
        int right = 0;
        int n = fruits.size();
        int sum = 0;
        int ans = 0;
        auto step = [&](int left, int right) -> int {
            if(fruits[right][0]<=startPos){
                return startPos - fruits[left][0];
            } else if(fruits[left][0]>= startPos){
                return fruits[right][0] - startPos;
            }else{
                return min(abs(startPos - fruits[right][0]),
                abs(startPos-fruits[left][0])) + fruits[right][0]- fruits[left][0];
            }
        };
        while(right<n){
            sum += fruits[right][1];
            while(left <= right && step(left, right) > k){
                sum -= fruits[left][1];
                left++;
            }
            ans = max(ans, sum);
            right++;
        }
        return ans;

    }
};
/*
1. The High-Level Idea: What are left, right, sum, and ans for?
Imagine you have a long piece of tape with fruit piles marked on it. You have two fingers, a left finger and a right finger, on this tape. The space between your fingers is your "window" of fruits.

left: The index of the leftmost fruit in your window.

right: The index of the rightmost fruit in your window.

sum: The total number of fruits you've collected in your current window.

ans: Your highest score (maximum fruits) so far.

The code's job is to slide this window across all the fruits. It starts with a tiny window, then expands it to the right (right++), and if the window becomes too big (takes too many steps), it shrinks it from the left (left++). At every valid window, it updates the ans.

2. The step function: A Step-by-Step Breakdown
This is the most critical part of the code. It's a little helper function that tells us how many steps are needed to visit all fruits in the current window.

What is auto step = [&](int left, int right) -> int { ... }?
auto: This is a C++ keyword that tells the compiler to automatically figure out the type of the variable. Here, the compiler sees that the right side is a lambda function, so step becomes a variable of that function's type.

step: The name of our helper function.

[&]: This is a "capture clause." It means this small function can access and use all the variables from the main function's scope (fruits, startPos, k, etc.).

(...) -> int: This defines the function's parameters (left, right) and its return type (int).

The Logic Inside step:
The step function determines the minimum steps needed to get from startPos to all fruits in the window [left, right]. It does this by considering three cases:

Case 1: The whole window is to your left.
if (fruits[right][0] <= startPos)

fruits[right][0] is the position of the rightmost fruit in the window.

Because the fruits are sorted by position, if the rightmost fruit is less than or equal to startPos, all the other fruits in the window must also be on your left.

Why return startPos - fruits[left][0]?

You are at startPos.

You only need to walk in one direction (left).

To collect all fruits, you just need to walk to the leftmost one (fruits[left][0]).

The total steps is simply the distance between startPos and fruits[left][0].

Case 2: The whole window is to your right.
else if (fruits[left][0] >= startPos)

fruits[left][0] is the position of the leftmost fruit in the window.

If the leftmost fruit is greater than or equal to startPos, all the other fruits in the window must also be on your right.

Why return fruits[right][0] - startPos?

You are at startPos.

You only need to walk in one direction (right).

To collect all fruits, you just need to walk to the rightmost one (fruits[right][0]).

The total steps is the distance between fruits[right][0] and startPos.

Case 3: You are inside the window (straddling).
else

This is the most complex case. startPos is somewhere between fruits[left][0] and fruits[right][0].

You have to visit both the leftmost and rightmost fruits. The optimal path is to go to one end, and then turn around and go to the other.

Why min(abs(startPos - fruits[right][0]), abs(startPos-fruits[left][0]))?

abs(...) calculates the absolute distance. For example, abs(5-2) is 3, and abs(2-5) is also 3. It just gives the distance, ignoring direction.

min(...) finds the shorter of the two distances: the distance from startPos to the rightmost fruit, or the distance from startPos to the leftmost fruit.

This is the distance of your first leg of the journey—you go to the closer of the two ends first.

Why + fruits[right][0]- fruits[left][0]?

fruits[right][0] - fruits[left][0] is the total distance between the two ends of the window.

The total steps for the round trip is: (distance to the closer end) + (total distance of the window). Think of it this way: you walk to the closer end, then you have to walk the entire length of the window to get to the other end.

3. The Main while Loops: Expanding and Shrinking
This is the "sliding window" part of the algorithm.

Outer Loop (while (right < n)):

This loop is responsible for expanding the window.

right++: The right pointer moves forward, one fruit at a time.

sum += fruits[right][1]: As the right pointer moves, we add the fruits from that new position to our sum.

Inner Loop (while (left <= right && step(left, right) > k)):

This loop is responsible for shrinking the window if it becomes too large.

step(left, right) > k: This is our check. If the steps needed for the current window are more than our budget k, the window is invalid.

sum -= fruits[left][1]: If the window is too big, we remove the fruit from the leftmost end to shrink it.

left++: The left pointer moves forward, making the window smaller.

This loop continues until the window is valid again (step <= k).

Final Steps in the Outer Loop:

ans = max(ans, sum): After the inner loop is finished and we have a valid window, we check if our current fruit sum is better than our best score so far (ans).

right++: The loop then repeats, moving right forward to expand the window again.

By the time the right pointer has moved all the way to the end of the fruits array, we have checked every possible valid window, and ans will hold the maximum number of fruits we can harvest.*/
