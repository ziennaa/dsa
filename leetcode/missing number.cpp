class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        int c = 0;
        for(int i=0; i<=n; i++){
            if(freq[i]==0){
                c = i;
            }
        }
        return c;
    }
};

// not matching tc and sc requirement
// need to find optimal sol and get back to this

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = (n*(n+1))/2;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        return total-sum;
    }
};
