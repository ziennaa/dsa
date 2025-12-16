3562. Maximum Profit from Trading Stocks with Discounts

Hard
Topics

Array
Dynamic Programming
Tree
Depth-First Search
Weekly Contest 451


class Solution {
    static constexpr long long NEG = (long long)-4e18;

    int B;
    vector<int> pres, fut;
    vector<vector<int>> child;
    vector<vector<long long>> dp0, dp1;

    vector<long long> mergeKnapsack(const vector<long long>& a, const vector<long long>& b) {
        vector<long long> res(B + 1, NEG);
        for (int i = 0; i <= B; ++i) {
            long long best = NEG;
            for (int j = 0; j <= i; ++j) {               
                long long av = a[i - j], bv = b[j];
                if (av <= NEG / 2 || bv <= NEG / 2) continue;
                best = max(best, av + bv);
            }
            res[i] = best;
        }
        for (int i = 1; i <= B; ++i) res[i] = max(res[i], res[i - 1]);
        return res;
    }

    vector<long long> solveNode(int u, int parentBought) {
        vector<long long> notBuy(B + 1, 0);        
        vector<long long> buy(B + 1, NEG);         
        int cost = parentBought ? (pres[u] / 2) : pres[u];
        long long profitHere = (long long)fut[u] - cost;
        if (cost <= B) {
            for (int b = cost; b <= B; ++b) buy[b] = profitHere;
            for (int b = 1; b <= B; ++b) buy[b] = max(buy[b], buy[b - 1]);
        }
        for (int v : child[u]) {
            notBuy = mergeKnapsack(notBuy, dp0[v]); 
            buy    = mergeKnapsack(buy,    dp1[v]); 
        }
        vector<long long> res(B + 1, 0);
        for (int b = 0; b <= B; ++b) res[b] = max(notBuy[b], buy[b]);
        for (int b = 1; b <= B; ++b) res[b] = max(res[b], res[b - 1]);
        return res;
    }
    void dfs(int u) {
        for (int v : child[u]) dfs(v);
        dp0[u] = solveNode(u, 0);
        dp1[u] = solveNode(u, 1);
    }
public:
    long long maxProfit(int n, vector<int>& present, vector<int>& future,
                        vector<vector<int>>& hierarchy, int budget) {
        B = budget;
        pres.assign(n + 1, 0);
        fut.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            pres[i] = present[i - 1];
            fut[i]  = future[i - 1];
        }
        child.assign(n + 1, {});
        for (auto &e : hierarchy) {
            int boss = e[0], emp = e[1];
            child[boss].push_back(emp);
        }
        dp0.assign(n + 1, vector<long long>(B + 1, 0));
        dp1.assign(n + 1, vector<long long>(B + 1, 0));

        dfs(1);                
        return dp0[1][B];       
    }
};
