class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long smooth_descent_periods = 0;
        int n = prices.size();
        smooth_descent_periods += n;
        long long k = 0;
        long long l = 1;
        for(int i=0; i<n-1; i++){
            if(prices[i+1] == prices[i] - 1){
                l++;
            }else{
                k += (l*(l-1))/2;
                l = 1;
            }
            //i++;
        }
        k += (l*(l-1))/2;
        smooth_descent_periods += k;
        return smooth_descent_periods;
    }
};
