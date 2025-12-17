class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
        vector<vector<int>> dp(k + 1, vector<int>(2, INT_MIN));
        dp[0][0] = 0;   
        for (int price : prices) {
            for (int t = k; t >= 1; t--) {
                dp[t][0] = max(dp[t][0], dp[t - 1][1] + price);
                dp[t][1] = max(dp[t][1], dp[t][0] - price);
            }
            dp[0][1] = max(dp[0][1], dp[0][0] - price);
        }
        int ans = 0;
        for (int t = 0; t <= k; t++)
            ans = max(ans, dp[t][0]);

        return ans;
    }
};
