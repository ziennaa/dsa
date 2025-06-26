class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        vector<pair<int, int>> k;
        for (int i = 0; i < nums.size(); i++) {
            k.push_back({nums[i], i});
        }
        sort(k.begin(), k.end());
        while (low <= high) {
            int mid = (low + high) / 2;

            if (target < k[mid].first) {
                high = mid - 1;
            } else if (target > k[mid].first) {
                low = mid + 1;
            } else {
                return k[mid].second;  
            }
        }
        return -1;  
    }
};
