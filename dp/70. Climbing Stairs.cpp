class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

/*
How to identify DP? 
count total no of ways
max/min
try all possible ways ::::: :::::: ::::::::: :::: RECURSION
*/
