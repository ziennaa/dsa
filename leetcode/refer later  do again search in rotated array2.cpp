class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        bool found = false;
        int c =0;
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                found = true;
            }
        }
        return found;
    }
};



/*
really stupid sol works fine is accepted but is ulitmaely bruteforcing and doesnt really doing what question is asking its stupid even tc not matching 
come back later and do it*/
