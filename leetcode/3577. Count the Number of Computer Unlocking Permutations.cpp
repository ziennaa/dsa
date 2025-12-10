class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long mod = 1e9+7;
        long long total = 0;
        for(int i=1; i<complexity.size(); i++){
            bool inc = complexity[0]<complexity[i];
            if(!inc){
                total = 0;
                return 0;
            }else{
                total = 1;
            }
        }
        if(total){
            long long ans = 1;
            for(int i=2; i<complexity.size(); i++){
                ans = (ans*i)%mod;
                ans %= mod;
            }
            return ans;
        }
        return total;
    }
};
