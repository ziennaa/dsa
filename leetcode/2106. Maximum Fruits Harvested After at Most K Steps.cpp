//2106. Maximum Fruits Harvested After at Most K Steps

// binary search sol

class Solution{
public: 
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k){
        int n = fruits.size();
        vector<int> sum(n+1);
        vector<int> index(n);
        for(int i=0; i<n; i++){
            sum[i+1] = sum[i] + fruits[i][1];
            index[i] = fruits[i][0]; 
        }
        int maxans = 0;
        for(int x=0; x<=k/2; x++){
            int left = startPos - x;
            int y = k - 2*x;
            int right = startPos + y;
            int start = lower_bound(index.begin(), index.end(), left)-index.begin();
            int end = upper_bound(index.begin(), index.end(), right)-index.begin();
            maxans = max(maxans, sum[end] - sum[start]);
            y = k-2*x;
            left = startPos-y;
            right = startPos+x;
            start = lower_bound(index.begin(), index.end(), left)-index.begin();
            end = upper_bound(index.begin(), index.end(), right)-index.begin();
            maxans = max(maxans, sum[end] - sum[start]);
        }
        return maxans;
    }
};

/*
The key constraints are:

You can only walk a maximum of k steps.

Each unit of distance you walk (e.g., from startPos to startPos + 1) costs one step.

You can walk left, right, or even turn around and go the other way.

The Core Idea: Why Binary Search and Prefix Sums?
The provided solution uses two powerful techniques: prefix sums and binary search. Let's understand why they are useful here.

1. Prefix Sums (for quick calculations):

Imagine you have a list of fruit amounts: [8, 3, 6]. The prefix sum would be a new list that tells you the total fruits up to each point.

fruits[0] = 8

fruits[1] = 3

fruits[2] = 6

The prefix sum array would be:
sum[0] = 0
sum[1] = 0 + 8 = 8
sum[2] = 8 + 3 = 11
sum[3] = 11 + 6 = 17

Now, if you want to know the total fruits between, say, index 1 and index 2, you can just do sum[3] - sum[1] = 17 - 8 = 9. This is much faster than adding 3 + 6 every time.

In our problem, we have fruits at specific positions, like [[2,8], [6,3], [8,6]]. The prefix sum array will be built based on the amount of fruits at each of these sorted positions. This allows us to quickly calculate the total fruits in any range of fruit positions.

2. Binary Search (for finding things efficiently):

The fruits array is sorted by position. This is a huge clue! When you have a sorted list and you need to find an element or a range of elements, binary search is often the fastest way.

In this problem, once we've decided on the range of positions we want to check (e.g., from position L to position R), we need to quickly find which fruit piles fall into this range. Since the fruit positions are sorted, we can use binary search (lower_bound and upper_bound in C++) to find the start and end indices of the fruit piles that are within our chosen range [L, R].

So, the combination of prefix sums and binary search lets us calculate the total fruits in any given harvest range [L, R] in a very efficient way (logarithmic time).

The Movement Strategy: The "Left-then-Right" and "Right-then-Left" Idea
This is the most crucial part of the algorithm. Instead of trying to explore every possible zig-zag path, the solution makes a key observation: the optimal path will always involve moving in one direction, possibly turning around once, and then moving in the other direction.

Think of it like this: if you have to turn around twice (e.g., left -> right -> left), you could have just stayed on the right side for longer and harvested more fruits, or stayed on the left side for longer. The extra turn is just a waste of steps. So, we only need to consider paths with at most one turn.

This gives us two main patterns:

Go left first, then turn right: You walk x steps to the left, then turn around and walk some distance to the right.

Go right first, then turn left: You walk x steps to the right, then turn around and walk some distance to the left.

Let's break down the first case: Go left first, then turn right.

You are at startPos.

You walk x steps to the left, reaching startPos - x.

You have used x steps. You have k - x steps remaining.

Now you turn around and walk to the right. The distance you need to walk to get back to startPos is x steps.

The total steps you've used so far is x (left) + x (right) = 2x.

You have k - 2x steps remaining to walk further to the right of startPos.

The farthest you can go to the right is startPos + (k - 2x).

So, in this scenario, you can harvest all fruits in the range [startPos - x, startPos + (k - 2x)].

The total steps used is x (to get to the leftmost point) + (startPos + (k - 2x)) - (startPos - x) (to travel from the leftmost point to the rightmost point) = x + (k - 2x + x) = x + k - x = k. This checks out.

The second case is symmetrical: Go right first, then turn left.

You walk x steps to the right, reaching startPos + x.

You have used x steps. k - x steps remain.

You turn around and walk left. It takes x steps to get back to startPos.

Total steps used so far is 2x. You have k - 2x steps remaining.

The farthest you can go to the left is startPos - (k - 2x).

So, in this scenario, you can harvest all fruits in the range [startPos - (k - 2x), startPos + x].

Visualizing the Code
Let's trace the loop in the code: for (int x = 0; x <= k / 2; x++).

The variable x represents the distance you walk in the first direction. Why does it only go up to k/2?

If you walk x steps in one direction and then y steps in the other, the total distance traveled is x + y + min(x, y) (the min part is for the "turnaround" distance).

Let's stick to our "move left x then right k-x" model. The total steps is x (left) + x (to get back to start) + (k-2x) (to go right). This is x + k - 2x + x = k. The total number of steps is always k.

But let's reconsider the movement. The total distance traveled is 2*left_distance + right_distance or 2*right_distance + left_distance. The 2* comes from the turnaround trip. The total steps must be <= k.

So, 2x + y <= k where x is the distance of the first leg and y is the distance of the second leg.

In the code, y is calculated as k - 2x. This is a bit of a shortcut. Let's think about the total distance traveled from startPos.

To get to startPos - x, you use x steps.

To get to startPos + y, you have to walk back x steps and then y steps. Total steps = x + (x+y) = 2x+y.

We are limited by k steps, so 2x+y <= k. The code sets y = k - 2x, which is the maximum possible y for a given x.

Since y must be non-negative, k - 2x >= 0, which means 2x <= k, or x <= k/2. This is why the loop only goes up to k/2.

So, the loop systematically checks every possible combination of "going x steps left and then turning" and "going x steps right and then turning." For each combination, it calculates the range of positions covered, and then uses binary search and prefix sums to quickly find the total fruits in that range. Finally, it keeps track of the maximum number of fruits found.

Example Walkthrough (Example 1)
fruits = [[2,8],[6,3],[8,6]]

startPos = 5

k = 4

Prefix Sums and Indices:

indices = [2, 6, 8]

sum = [0, 8, 11, 17]

Loop for x from 0 to k/2 (which is 2):

x = 0:

Left first: You don't move left at all. The entire k=4 steps are used to go right.

left = 5 - 0 = 5

y = k - 2*0 = 4

right = 5 + 4 = 9

Range to check: [5, 9].

Fruits at positions 6 and 8 are in this range.

Using binary search and prefix sums, we find 3 + 6 = 9 fruits. ans = 9.

Right first: You don't move right at all. The entire k=4 steps are used to go left.

right = 5 + 0 = 5

y = k - 2*0 = 4

left = 5 - 4 = 1

Range to check: [1, 5].

Fruits at position 2 are in this range.

Using binary search and prefix sums, we find 8 fruits. ans is still 9.

x = 1:

Left first: Move 1 step left, turn, move right.

left = 5 - 1 = 4

y = k - 2*1 = 2

right = 5 + 2 = 7

Range to check: [4, 7].

Fruits at position 6 are in this range.

Using binary search and prefix sums, we find 3 fruits. ans is still 9.

Right first: Move 1 step right, turn, move left.

right = 5 + 1 = 6

y = k - 2*1 = 2

left = 5 - 2 = 3

Range to check: [3, 6].

Fruits at position 6 are in this range.

Using binary search and prefix sums, we find 3 fruits. ans is still 9.

x = 2:

Left first: Move 2 steps left, turn, move right.

left = 5 - 2 = 3

y = k - 2*2 = 0

right = 5 + 0 = 5

Range to check: [3, 5].

No fruits are in this range. Fruits found: 0. ans is still 9.

Right first: Move 2 steps right, turn, move left.

right = 5 + 2 = 7

y = k - 2*2 = 0

left = 5 - 0 = 5

Range to check: [5, 7].

Fruits at position 6 are in this range.

Fruits found: 3. ans is still 9.

*/

/*
lower_bound(indices.begin(), indices.end(), left): This part of the code performs a binary search on the indices vector. Instead of returning an integer index, it returns an iterator. An iterator is a concept in C++ that acts like a pointer, pointing to a specific element within a container (like a vector). In this case, it's pointing to the first element in indices that is greater than or equal to left.

indices.begin(): This returns an iterator that points to the very first element of the indices vector (at index 0).

The Subtraction (-): When you subtract two iterators that point to elements within the same container, the result is the distance between them, expressed as an integer.

So, lower_bound(...) - indices.begin() is essentially calculating:
(The iterator pointing to the found element) - (The iterator pointing to the first element)

The result of this subtraction is the zero-based integer index of the found element.*/

