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

// tc not mnatching above
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};


// here we sorted only left halft and right half
/*
4567 not here
so move to right half 01233
    founded here!!!*/
