class Solution {  
public:
    int specialTriplets(vector<int>& nums) {
        int mod = 1e9+7;
        int total = 0;
        int n = nums.size();
        map<long long, long long> freqprev;
        map<long long, long long> freqnext;
        for(int x: nums){
            freqnext[x]++;
        }
        for(int j=0; j<n; j++){
            long long num = nums[j];
            freqnext[num]--;
            long long t = (2LL*num)%mod;
            long long leftcount = freqprev[t];
            long long rightcount = freqnext[t];
            total = (total +(leftcount*rightcount)%mod)%mod;
            freqprev[num]++;
        }
        return total;
    }
};
